/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 20:09:21 by selhilal          #+#    #+#             */
/*   Updated: 2023/07/29 09:42:09 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

void	outorappand(char *text, int *i, t_token **token)
{
	int		f;
	int		j;
	char	*table;

	j = *i;
	table = NULL;
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
		ft_back(token, ft_lstnew(7, table));
	else if (f == 1)
		ft_back(token, ft_lstnew(3, table));
	free(table);
}

void	inorherdoc(char *text, int *i, t_token **token)
{
	int		f;
	int		j;
	char	*table;

	table = NULL;
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
		ft_back(token, ft_lstnew(9, table));
	if (f == 1)
		ft_back(token, ft_lstnew(2, table));
	free(table);
}

void	word(char *text, int *i, t_token **token, char **envp)
{
	int		j;
	int		k;
	int		t;
	char	*tex;
	char	*exet;

	j = *i;
	t = *i;
	k = 0;
	exet = NULL;
	tex = ft_strdup("");
	while (text[j] && !notword(text[j]) && !spaces(text[j]) && text[j] != '$')
		j += 1;
	k = j;
	if (text[j] && text[j] == '$')
		tex = dollar(text, &j, token, envp);
	exet = ft_substr(text, t, k - t);
	*i = j;
	ft_back(token, ft_lstnew(1, ft_strjoin(exet, tex)));
	free(tex);
}

void	space(char *text, int *i, t_token **token)
{
	int		j;
	int		k;
	int		t;
	char	*table;

	table = NULL;
	j = *i;
	t = *i;
	k = 0;
	while (spaces(text[j]) && !notword(text[j]))
		j += 1;
	table = ft_substr(text, t, j - t);
	ft_back(token, ft_lstnew(10, table));
	*i = j;
	free(table);
}
