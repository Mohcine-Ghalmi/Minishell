/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qudes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:07:10 by selhilal          #+#    #+#             */
/*   Updated: 2023/07/28 18:23:46 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	qudes(char *text, int *i, t_token **token, char **envp)
{
	int		q;
	char	*exet;
	int		t;
	int		m;
	char	*tex;
	int 	flag;

	tex = ft_strdup("");
	exet = NULL;
	q = text[*i];
	flag = 0;
	*i += 1;
	m = 0;
	t = 0;
	t = *i;
	if (q == '\'')
	{
		while (text[t] && text[t] != q)
			t += 1;
		m = t;
	}
	else if (q == '\"')
	{
		while (text[t] && text[t] != q)
		{
			if (text[t] == '$')
			{
				flag = 1;
				tex = ft_strjoin(tex, dollar(text, &t, token, envp));
			}
			else
				t += 1;
		}
		if (!flag)
			m = t;
	}
	t += 1;
	exet = ft_substr(text, *i, m - *i);
	*i = t;
	if (q == '\'')
		ft_lstadd_back(token, ft_lstnew(6, exet));
	else if (q == '\"')
		ft_lstadd_back(token, ft_lstnew(5, ft_strjoin(exet, tex)));
	//free(exet);
	free(tex);
}
