/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:38:24 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/06 17:05:32 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

void	signl_herdoc(int sig)
{
	(void)sig;
	ioctl(0, TIOCSTI, "\4");
	if (g_test == 3)
		g_test = 4;
	else
		g_test = -1;
}


int	heredoc_file(char *limiter, int outfile)
{
	char	*str;
	char	*end;

	if (outfile < 0)
		return (1);
	end = ft_strjoin(limiter, "\n");
	while (1) 
	{
		signal(SIGINT, signl_herdoc);
		str = readline("> ");
		if (!str)
			return (1);
		str = ft_strjoin(str, "\n");
		if (g_test != 3)
			puts("input");
		ft_putstr_fd(str, outfile);
		if (!ft_strncmp(end, str, ft_strlen(end)))
			break ;
		free(str);
		// signal(SIGINT, signl_herdoc);
		//str = readline("> ");
	}
	free(end);
	free(str);
	close(outfile);
	if (g_test == -1 || g_test == 4)
		return (1);
	return (0);
}

int	heredoc(char *limiter)
{
	int	fd[2];

	pipe(fd);
	if (fd < 0)
		return (0);
	if (heredoc_file(limiter, fd[1]))
		return (-1);
	return (fd[0]);
}

int	heredocfile(t_lsttoken **token, int in)
{
	if (g_test != -1 && g_test != 4)
		in = heredoc((*token)->next->str);
	if ((*token)->next)
		(*token) = (*token)->next;
	return (in);
}

int	main(int argc, char **argv, char **envp)
{
	t_env	*new_envp;

	(void)argv;
	if (argc > 1)
	{
		printf("no arguments\n");
		return (0);
	}
	new_envp = envirment(envp);
	execute_minishell(new_envp);
	ft_lstclear_env(&new_envp);
	return (0);
}
