/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:38:24 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/06 20:23:37 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

void	signl_herdoc(int sig)
{
	(void)sig;
	ioctl(0, TIOCSTI, "\4");
		g_test = -1;
}

char	*her_qudes(char *text, char **envp)
{
	char	*table;
	int 	t;

	t = 0;
	table = NULL;
	while (text[t])
	{
		if (text[t] == '$')
			table = ft_strjoin(table, dollar(text, &t, envp));
		else
		{
			table = join_char(table, text[t]);
			(t)++;
		}
	}
	return (table);
}

int	heredoc_file(char *limiter, int outfile, char **envp)
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
			str = her_qudes(str, envp);
		if (!ft_strncmp(end, str, ft_strlen(end)))
			break ;
		ft_putstr_fd(str, outfile);
		free(str);
	}
	free(end);
	free(str);
	close(outfile);
	if (g_test == -1 || g_test == 4)
		return (1);
	return (0);
}

int	heredoc(char *limiter, char **envp)
{
	int	fd[2];

	pipe(fd);
	if (fd < 0)
		return (0);
	if (heredoc_file(limiter, fd[1], envp))
		return (-1);
	return (fd[0]);
}

int	heredocfile(t_lsttoken **token, int in, char **envp)
{
	if (g_test != -1 && g_test != 4)
		in = heredoc((*token)->next->str, envp);
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
