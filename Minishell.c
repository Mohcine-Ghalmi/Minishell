/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:38:24 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/05 19:08:42 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

void	signl_herdoc(int sig)
{
	(void)sig;
	ioctl(0, TIOCSTI, "\4");
	g_test = -1;
}

int	heredoc_file(char *limiter, int outfile)
{
	char	*str;
	char	*end;

	if (outfile < 0)
		return (1);
	signal(SIGINT, signl_herdoc);
	end = ft_strjoin(limiter, "\n");
	str = readline("> ");
	if (!str)
		return (1);
	while (1) 
	{
		str = ft_strjoin(str, "\n");
		if (str == NULL)
			return (1);
		if (!ft_strncmp(end, str, ft_strlen(end)))
			break;
		ft_putstr_fd(str, outfile);
		free(str);
		str = readline("> ");
	}
	free(end);
	free(str);
	close(outfile);
	if (g_test == -1)
		return (1);
	return (0);
}

int	heredoc(char *limiter)
{
	int	fd[2];

	pipe(fd);
	g_test = 0;
	if (fd < 0)
		return (0);
	if (heredoc_file(limiter, fd[1]))
		return (-1);
	return (fd[0]);
}

int	heredocfile(t_lsttoken **token, int in)
{
	if (g_test != -1)
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
