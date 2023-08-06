/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:38:24 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/07 00:50:38 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

void	signl_herdoc(int sig)
{
	(void)sig;
	ioctl(0, TIOCSTI, "\4");
	g_test = -1;
}

char	*herdoc_dollar(char *text, int *i, char **envp)
{
	char	*table;
	char	*dolar;

	table = creat_table(text, i);
	if (!ft_strlen(table) || (!text[*i] || text[*i] == '\n' || text[*i] == ' '))
		return (free(table), ft_strdup("$"));
	dolar = out_dollars(table, envp);
	return (free(table), dolar);
}

char	*her_qudes(char *text, char **envp)
{
	char	*table;
	int		t;

	t = 0;
	table = NULL;
	while (text[t])
	{
		if (text[t] == '$')
			table = ft_strjoin(table, herdoc_dollar(text, &t, envp));
		else
		{
			table = join_char(table, text[t]);
			(t)++;
		}
	}
	return (table);
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
