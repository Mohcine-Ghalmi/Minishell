/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qudes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:07:10 by selhilal          #+#    #+#             */
/*   Updated: 2023/08/08 17:41:30 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*single_qudes(char *text, int *t)
{
	int		m;
	int		i;

	m = 0;
	i = 0;
	i = *t;
	if (text[*t] == '\'')
	{
		if (text[*t] == ' ')
			return (ft_strdup(""));
	}
	while (text[*t] && text[*t] != '\'')
		*t += 1;
	m = *t;
	return (ft_substr(text, i, m - i));
}

char	*join_char(char *str, char c)
{
	char	*new;
	int		i;

	i = 0;
	if (!str)
		str = ft_strdup("");
	new = malloc(ft_strlen(str) + 2);
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i++] = c;
	new[i] = '\0';
	free(str);
	return (new);
}

char	*double_qudes(char *text, int *t, char **evp)
{
	char	*table;
	char	*dol;

	table = NULL;
	dol = NULL;
	if (text[*t] == '\"')
	{
		(*t)++;
		if (text[*t] == ' ')
			return (ft_strdup(""));
	}
	while (text[*t] && text[*t] != '\"')
	{
		if (text[*t] == '$')
		{
			dol = dollar(text, t, evp);
			table = ft_strjoin(table, dol);
			free(dol);
		}
		else
			table = join_char(table, text[(*t)++]);
	}
	return (table);
}

void	qudes(char *text, int *i, t_token **token, char **envp)
{
	int		q;
	int		t;

	q = text[*i];
	*i += 1;
	t = *i;
	g_test = 3;
	if (q == '\'')
	{
		ft_back(token, ft_lstnew(6, single_qudes(text, &t)));
		t++;
	}
	else if (q == '\"')
	{
		ft_back(token, ft_lstnew(5, double_qudes(text, &t, envp)));
		t++;
	}
	*i = t;
}
