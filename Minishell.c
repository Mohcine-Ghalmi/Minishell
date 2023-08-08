/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:38:24 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/08 04:50:44 by mghalmi          ###   ########.fr       */
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
	int		l;

	l = 0;
	table = creat_table(text, i);
	l = *i;
	l--;
	if (!ft_strlen(table) || (!text[l] || text[l] == '\n' || text[l] == ' '))
		return (free(table), ft_strdup("$"));
	dolar = out_dollars(table, envp);
	return (dolar);
}

char	*her_qudes(char *text, char **envp)
{
	char	*table;
	int		t;
	char	*dol;

	dol = NULL;
	t = 0;
	table = NULL;
	while (text[t])
	{
		if (text[t] == '$')
		{
			dol = herdoc_dollar(text, &t, envp);
			table = ft_strjoin(table, dol);
			free(dol);
		}
		else
		{
			table = join_char(table, text[t]);
			(t)++;
		}
	}
	free(text);
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
