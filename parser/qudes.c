/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qudes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:07:10 by selhilal          #+#    #+#             */
/*   Updated: 2023/08/05 18:38:58 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	single_qudes(char *text, int *t, int i, t_token **token)
{
	char	*exet;
	int		m;

	m = 0;
	if (text[*t] == '\'')
	{
		*t += 1;
		return (ft_back(token, ft_lstnew(1, ft_strdup(""))));
	}
	while (text[*t] && text[*t] != '\'')
		*t += 1;
	m = *t;
	ft_back(token, ft_lstnew(6, ft_substr(text, i, m - i)));
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
	return (new);
}

char	*double_qudes(char *text, int *t, char **evp)
{
	char	*table;
	int		j;

	table = NULL;
	if (text[*t] == '\"')
	{
		(*t)++;
		if (text[*t] == ' ')
			return (ft_strdup(""));
	}
	while (text[*t] && text[*t] != '\"')
	{
		if (text[*t] == '$')
			table = ft_strjoin(table, dollar(text, t, evp));
		else
		{
			table = join_char(table, text[*t]);
			(*t)++;
		}
	}
	(*t)++;
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
		ft_back(token, ft_lstnew(5, double_qudes(text, &t, envp)));
	*i = t;
}
