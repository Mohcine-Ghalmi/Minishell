/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_herdoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 22:08:35 by selhilal          #+#    #+#             */
/*   Updated: 2023/08/06 22:12:16 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

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
