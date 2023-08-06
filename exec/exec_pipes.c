/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 18:34:15 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/06 05:26:31 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"
#include "exec.h"

void	piper_norm(t_node *cmd, int pipefd[2])
{
	close(pipefd[0]);
	if (cmd->fdout > 2)
		dup2(cmd->fdout, STDOUT_FILENO);
	else if (cmd && cmd->cmd != NULL && ft_lstsize_node(cmd) > 1)
		dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[1]);
	// if (cmd->fdin > 2)
	// 	dup2(cmd->fdin, STDIN_FILENO);
	// else
	// 	dup2(pipefd[0], STDIN_FILENO);
}

void	piper_dup(t_node *cmd, int pipefd[2])
{
	close(pipefd[1]);
	if (cmd->next)
	{
		if (cmd->next->fdin > 2)
			dup2(cmd->next->fdin, STDIN_FILENO);
		else
			dup2(pipefd[0], STDIN_FILENO);
	}
	close(pipefd[0]);
}

void remove_carriage_return(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] == '\r')
            ft_memmove(&str[i], &str[i + 1], ft_strlen(str) - i);
}

void	piper(t_node *cmd, t_env *new_env)
{
	pid_t	pid;
	int		pipefd[2];
	int		b;

	b = 0;
	// if (!cmd->cmd[0])
	// 	return ;
	signal(SIGINT, SIG_IGN);
	if (pipe(pipefd) < 0)
		return ;
	pid = fork();
	if (pid)
		piper_dup(cmd, pipefd);
	else
	{
		signal(SIGINT, SIG_DFL);
		// signal(SIGQUIT, SIG_DFL);
		piper_norm(cmd, pipefd);
		b = check_builtins(cmd->cmd, new_env);
		if (b < 2)
			exit(b);
		if (!cmd->cmd[0])
			exit(127);
		exec(cmd->cmd, env_exec(new_env));
	}
	closepipe(pipefd);
	close_files(cmd->fdin, cmd->fdout);
}

void	update_and_wait(int ifcond, int status, t_env *envp)
{
	while (wait(&status) != -1)
		;
	if (WTERMSIG(status))
	{
		if (WTERMSIG(status) == 2)
			ft_putstr_fd("\n", 1);
		else if (WTERMSIG(status) == 3)
			ft_putstr_fd("Quit: 3\n", 1);
		update_status(g_test, envp, 1);
	}
	else if (ifcond < 2)
		update_status(ifcond, envp, 1);
	else
		update_status(WEXITSTATUS(status), envp, 1);
}

void	execution(t_node *new, t_env *envp)
{
	int				status;
	unsigned int	ifcond;
	int				in;
	int				out;

	ifcond = 2;
	status = 0;
	in = dup(0);
	out = dup(1);
	if (ft_lstsize_node(new) == 1)
		ifcond = first_built(new, envp);
	if (new && ifcond == 2)
	{
		dup2(new->fdin, STDIN_FILENO);
		while (new)
		{
			piper(new, envp);
			new = new->next;
		}
	}
	dup2(in, STDIN_FILENO);
	dup2(out, STDOUT_FILENO);
	close_files(in, out);
	update_and_wait(ifcond, status, envp);
}
