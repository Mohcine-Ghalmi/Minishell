/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 18:34:15 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/05 01:57:21 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"
#include "exec.h"

void	piper_norm(t_node *cmd, int pipefd[2])
{
	close(pipefd[0]);
	if (cmd->fdout == -1 || cmd->fdin == -1)
		exit(1);
	if (cmd->fdout > 2)
		dup2(cmd->fdout, STDOUT_FILENO);
	else if (cmd &&  ft_lstsize_node(cmd) > 1)
		dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[1]);
}

void	piper_dup(t_node *cmd, int pipefd[2])
{
	close(pipefd[1]);
	if (cmd->fdin > 2)
		dup2(cmd->fdin, STDIN_FILENO);
	else
		dup2(pipefd[0], STDIN_FILENO);
}

void	piper(t_node *cmd, t_env *new_env)
{
	pid_t	pid;
	char	**exec_enev;
	int		pipefd[2];
	int		b;

	b = 0;
	if (!cmd->cmd[0])
		return ;
	signal(SIGINT, SIG_IGN);
	if (pipe(pipefd) < 0)
		return ;
	pid = fork();
	if (pid)
		piper_dup(cmd, pipefd);
	else
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		piper_norm(cmd, pipefd);
		exec_enev = env_exec(new_env);
		b = check_builtins(cmd->cmd, new_env);
		if (b < 2)
			exit(b);
		exec(cmd->cmd, exec_enev);
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
	}else if (ifcond < 2)
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
	update_and_wait(ifcond, status, envp);
}
