/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 20:09:21 by selhilal          #+#    #+#             */
/*   Updated: 2023/07/25 16:48:54 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	outorappand(char *text, int *i, t_token **token)
{
	int		f;
	int		j;
	char	*table;

	j = *i;
	if (text[*i + 1] != '>')
	{
		f = 1;
		*i += 1;
	}
	if (text[*i + 1] == '>' )
	{
		f = 2;
		*i += 2;
	}
	table = ft_substr(text, j, *i - j);
	if (f == 2)
		ft_lstadd_back(token, ft_lstnew(7, table));
	else if (f == 1)
		ft_lstadd_back(token, ft_lstnew(3, table));
}

void	inorherdoc(char *text, int *i, t_token **token)
{
	int		f;
	int		j;
	char	*table;

	j = *i;
	if (text[*i + 1] != '<')
	{
		*i += 1;
		f = 1;
	}
	if (text[*i + 1] == '<' )
	{
		f = 2;
		*i += 2;
	}
	table = ft_substr(text, j, *i - j);
	if (f == 2)
		ft_lstadd_back(token, ft_lstnew(9, table));
	if (f == 1)
		ft_lstadd_back(token, ft_lstnew(2, table));
}

void	word(char *text, int *i, t_token **token, char **envp)
{
	int		j;
	int		k;
	int		t;
	char	*tex;
	char	*table;

	j = *i;
	t = *i;
	k = 0;
	tex = NULL;
	while (text[j] && !notword(text[j]) && !spaces(text[j]) && text[j] != '$')
		j += 1;
	k = j;
	if (text[j] && text[j] == '$')
		tex = dollar(text, &j, token, envp);
	table = ft_substr(text, t, k - t);
	*i = j;
	ft_lstadd_back(token, ft_lstnew(1, ft_strjoin(table, tex)));
}

void	space(char *text, int *i, t_token **token)
{
	int		j;
	int		k;
	int		t;
	char	*table;

	j = *i;
	t = *i;
	k = 0;
	while (spaces(text[j]) && !notword(text[j]))
		j += 1;
	table = ft_substr(text, t, j - t);
	ft_lstadd_back(token, ft_lstnew(10, table));
	*i = j;
}
