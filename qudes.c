/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qudes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:07:10 by selhilal          #+#    #+#             */
/*   Updated: 2023/07/26 10:11:19 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	qudes(char *text, int *i, t_token **token, char **envp)
{
	int		q;
	char	*table;
	int		t;
	int		m;
	char	*tex;
	int 	flag;

	tex = NULL;
	q = text[*i];
	flag = 0;
	*i += 1;
	t = *i;
	if (q == '\'')
	{
		while (text[t] && text[t] != q)
			t += 1;
		m = t;
	}
	if (q == '\"')
	{
		while (text[t] && text[t] != q)
		{
			if (text[t] == '$')
			{
				m = t;
				flag = 1;
				tex = dollar(text, &t, token, envp);
			}
			t += 1;
		}
		if (!flag)
			m = t;
	}
	t += 1;
	table = ft_substr(text, *i, m - *i);
	*i = t;
	if (q == '\'')
		ft_lstadd_back(token, ft_lstnew(6, table));
	if (q == '\"')
		ft_lstadd_back(token, ft_lstnew(5, ft_strjoin(table, tex)));
}
