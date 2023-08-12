/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 20:09:21 by selhilal          #+#    #+#             */
/*   Updated: 2023/08/12 15:57:57 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	outorappand(char *text, int *i, t_token **token)
{
	int		f;
	int		j;
	char	*table;

	j = *i;
	if (!text)
		return ;
	table = NULL;
	if (text[*i + 1] != '>')
		f = 1;
	if (text[*i + 1] == '>')
	{
		f = 2;
		*i += 1;
	}
	*i += 1;
	table = ft_substr(text, j, *i - j);
	if (f == 2)
		ft_back(token, ft_lstnew(7, table));
	else if (f == 1)
		ft_back(token, ft_lstnew(3, table));
}

void	inorherdoc(char *text, int *i, t_token **token)
{
	int		f;
	int		j;
	char	*table;

	table = NULL;
	j = *i;
	if (text[*i + 1] != '<')
		f = 1;
	if (text[*i + 1] == '<' )
	{
		f = 2;
		*i += 1;
	}
	*i += 1;
	table = ft_substr(text, j, *i - j);
	if (f == 2)
		ft_back(token, ft_lstnew(9, table));
	if (f == 1)
		ft_back(token, ft_lstnew(2, table));
}

int	exec_dollar(char *str, t_token **token)
{
	int		i;
	int		j;
	char	**splited;

	i = 0;
	if (!str)
		return (0);
	splited = ft_split(str, ' ');
	while (splited[i])
		i++;
	if (i > 0)
	{
		j = 0;
		while (j < i)
		{
			ft_back(token, ft_lstnew(1, ft_strdup(splited[j++])));
			if (j < i)
				ft_back(token, ft_lstnew(10, ft_strdup(" ")));
		}
		free_double(splited);
		return (1);
	}
	free_double(splited);
	return (0);
}

void	word(char *text, int *i, t_token **token, char **envp)
{
	int		j;
	int		k;
	int		t;
	char	*tex;
	char	*exet;

	if (!text || !envp)
	{
		(*i)++;
		return ;
	}
	j = *i;
	t = *i;
	tex = extract_dollar_value(text, &j, envp, &k);
	exet = ft_substr(text, t, k - t);
	*i = j;
	if (!exet[0])
		if (exec_dollar(tex, token))
			return (free(tex), free(exet));
	ft_back(token, ft_lstnew(1, ft_strjoin_word(exet, tex)));
	free(exet);
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
	ft_back(token, ft_lstnew(10, ft_substr(text, t, j - t)));
	*i = j;
}
