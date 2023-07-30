/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qudes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:07:10 by selhilal          #+#    #+#             */
/*   Updated: 2023/07/30 15:01:02 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

void	single_qudes(char *text, int *t, int i, t_token **token)
{
	char	*exet;
	int		m;

	m = 0;
	while (text[*t] && text[*t] != '\'')
		*t += 1;
	m = *t;
	ft_back(token, ft_lstnew(6, ft_substr(text, i, m - i)));
}

char	*double_qudes(char *text, int *t, int i, char **evp)
{
	char	*table;
	char	*globel;

	table = NULL;
	globel = NULL;
	while (text[*t] && text[*t] != '\"')
	{
		if (text[*t] == '$')
		{
			globel = dollar(text, t, evp);
			// (*t)++;
			i = *t + 1;
			table = ft_strjoin(table, globel);
			free(globel);
		}
		else
		{
			(*t)++;
			if (text[*t] == '$')
				table = ft_strjoin(table, ft_substr(text, i, *t - 1));
		}
	}
	//t += 1;
	table = ft_strjoin(table, ft_substr(text, i, *t + 1));
	return (table);
}

void	qudes(char *text, int *i, t_token **token, char **envp)
{
	int		q;
	int		t;

	q = text[*i];
	*i += 1;
	t = *i;
	if (q == '\'')
		single_qudes(text, &t, *i, token);
	else if (q == '\"')
		ft_back(token, ft_lstnew(5, double_qudes(text, &t, *i, envp)));
	//t += 1;
	*i = t;
}
