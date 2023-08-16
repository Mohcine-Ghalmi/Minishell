/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 18:34:15 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/17 00:31:52 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"
#include "exec.h"

void	piper_norm(t_node *cmd, int pipefd[2])
{
	if (cmd->fdin == -1 || cmd->fdout == -1)
		exit(0);
	close(pipefd[0]);
	if (cmd->fdout > 2)
		dup2(cmd->fdout, STDOUT_FILENO);
	else if (cmd && cmd->cmd != NULL && ft_lstsize_node(cmd) > 1)
		dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[1]);
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

void	dir(char *cmd)
{
	DIR	*direct;

	direct = opendir(cmd);
	if (direct)
	{
		ft_putstr_fd("minishell:", 2);
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": is a directory\n", 2);
		exit(126);
	}
}

int	piper(t_node *cmd, t_env *new_env)
{
	pid_t	pid;
	int		pipefd[2];
	int		b;

	b = 0;
	signal(SIGINT, SIG_IGN);
	if (pipe(pipefd) == -1 && ft_lstsize_node(cmd) == 1)
		return (perror("Pipe "), -1);
	pid = fork();
	if (pid == -1)
		return (perror("fork"), -1);
	if (pid)
		piper_dup(cmd, pipefd);
	else
	{
		for_seg();
		piper_norm(cmd, pipefd);
		b = check_builtins(cmd->cmd, new_env, 1);
		if (!cmd->cmd[0] || b < 2)
			exit(b);
		dir(cmd->cmd[0]);
		exec(cmd->cmd, env_exec(new_env));
	}
	closepipe(pipefd);
	return (close_files(cmd->fdin, cmd->fdout), 0);
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
			status = piper(new, envp);
			if (status == -1)
				break ;
			new = new->next;
		}
	}
	clone_std(in, out);
	close_files(in, out);
	return (close_all_fd(), update_and_wait(ifcond, status, envp));
}
