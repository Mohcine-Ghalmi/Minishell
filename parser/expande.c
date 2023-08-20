/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expande.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 20:17:25 by selhilal          #+#    #+#             */
/*   Updated: 2023/08/20 13:24:00 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	dollar_length(char *text, int i)
{
	int	l;
	int	j;

	j = 0;
	l = i + 1;
	if ((text[l] == '\'') || (text[l] == '\"' ))
		return (-1);
	while (text[l] && ft_isalnum(text[l]) && text[l] != '$')
	{
		j += 1;
		l += 1;
	}
	return (l);
}

char	*creat_table(char *text, int *i, int *flag)
{
	int		l;
	int		j;
	int		k;
	char	*table;

	j = 0;
	l = 0;
	l = *i + 1;
	k = l;
	table = ft_calloc(1, dollar_length(text, *i) + 1);
	if (text[l] && ft_isdigit(text[l]))
	{
		l += 1;
		*flag = 1;
	}
	if (text[l] && (ft_isalpha(text[l]) || text[l] == '?'))
	{
		while (text[l] && text[l] != '$' && ft_isalnum(text[l]))
			table[j++] = text[l++];
		table[j] = '\0';
	}
	if (dollar_length(text, k) == -1)
		*flag = 1;
	return (*i = l, table);
}

char	*dollar(char *text, int *i, char **envp)
{
	char	*table;
	char	*dolar;
	int		flag;

	flag = 0;
	table = creat_table(text, i, &flag);
	if (!ft_strlen(table) && flag == 0)
		return (free(table), ft_strdup("$"));
	if (!ft_strlen(table) && flag == 1)
		return (free(table), ft_strdup(""));
	dolar = out_dollars(table, envp);
	return (dolar);
}

int	ft_strncmp(char *str1, char *str2, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	if (!str1 || !str2)
		return (0);
	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return (s1[i] - s2[i]);
}

char	*out_dollars(char *key, char **env)
{
	int		i;

	i = 0;
	key = join_char(key, '=');
	while (env[i])
	{
		if (!ft_strncmp(key, env[i], ft_strlen1(key)))
		{
			free(key);
			return (ft_substr(env[i], first_equale(env[i]), strlen(env[i]))); 
		}
		i++;
	}
	free(key);
	return (ft_strdup(""));
}
