/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 18:34:15 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/06 22:23:51 by selhilal         ###   ########.fr       */
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

void	piper(t_node *cmd, t_env *new_env)
{
	pid_t	pid;
	int		pipefd[2];
	int		b;

	b = 0;
	signal(SIGINT, SIG_IGN);
	if (pipe(pipefd) < 0)
		return ;
	pid = fork();
	if (pid)
		piper_dup(cmd, pipefd);
	else
	{
		signal(SIGINT, SIG_DFL);
		piper_norm(cmd, pipefd);
		b = check_builtins(cmd->cmd, new_env);
		if (b < 2)
			exit(b);
		if (!cmd->cmd[0])
			exit(0);
		dir(cmd->cmd[0]);
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
		{
			ft_putstr_fd("\n", 1);
			update_status(130, envp, 1);
		}
		else if (WTERMSIG(status) == 3)
		{
			ft_putstr_fd("Quit: 3\n", 1);
			update_status(131, envp, 1);
		}
		else
			update_status(0, envp, 1);
	}
	else if (ifcond < 2)
		update_status(ifcond, envp, 1);
	else
		update_status(WEXITSTATUS(status), envp, 1);
}
