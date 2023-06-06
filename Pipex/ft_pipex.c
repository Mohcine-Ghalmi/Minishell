/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:13:45 by mghalmi           #+#    #+#             */
/*   Updated: 2023/01/26 16:28:23 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pidwait(pid_t pid1, pid_t pid2)
{
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

void	closepipe(int pipefd[2])
{
	close(pipefd[1]);
	close(pipefd[0]);
}

void	pipex1(char *cmd1, char *cmd2, char **env)
{
	pid_t	pid1;
	pid_t	pid2;
	int		pipefd[2];

	if (pipe(pipefd) < 0)
		exit(1);
	pid1 = fork();
	if (pid1 == 0)
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		exec(cmd1, env);
	}
	pid2 = fork();
	if (pid2 == -1 || pid1 == -1)
		exit(1);
	if (pid2 == 0)
	{		
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		exec(cmd2, env);
	}
	closepipe(pipefd);
	pidwait(pid1, pid2);
}

void	pipex(char *cmd1, char **env)
{
	pid_t	pid;
	int		pipefd[2];

	pipe(pipefd);
	pid = fork();
	if (pid)
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
	else
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		exec(cmd1, env);
	}
	closepipe(pipefd);
}
