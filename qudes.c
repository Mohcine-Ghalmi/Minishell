/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qudes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:07:10 by selhilal          #+#    #+#             */
/*   Updated: 2023/07/29 09:49:40 by selhilal         ###   ########.fr       */
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

void	qudes(char *text, int *i, t_token **token, char **envp)
{
	int		q;
	char	*tex;
	int		t;
	int		m;
	int		flag;

	tex = ft_strdup("");
	q = text[*i];
	flag = 0;
	*i += 1;
	m = 0;
	t = *i;
	if (q == '\'')
		single_qudes(text, &t, *i, token);
	else if (q == '\"')
	{
		while (text[t] && text[t] != q)
		{
			if (text[t] == '$')
			{
				flag = 1;
				tex = ft_strjoin(tex, dollar(text, &t, token, envp));
			}
			t += 1;
		}
		if (!flag)
			m = t;
	}
	t += 1;
	ft_back(token, ft_lstnew(5, ft_strjoin(ft_substr(text, *i, m - *i), tex)));
	*i = t;
	free(tex);
}
