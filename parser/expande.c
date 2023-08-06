/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expande.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 20:17:25 by selhilal          #+#    #+#             */
/*   Updated: 2023/08/06 21:10:12 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	dollar_length(char *text, int i)
{
	int	l;
	int	j;

	j = 0;
	l = i + 1;
	while (text[l] && ft_isalnum(text[l]) && text[l] != '$')
	{
		j += 1;
		l += 1;
	}
	return (l);
}

char	*creat_table(char *text, int *i)
{
	int		l;
	int		j;
	char	*table;

	j = 0;
	l = 0;
	l = *i + 1;
	table = ft_calloc(1, dollar_length(text, *i));
	while (text[l] && ft_isalnum(text[l]) && text[l] != '$')
	{
		if (ft_isdigit(text[l]))
		{
			l += 1;
			break ;
		}
		else
		{
			table[j] = text[l];
			j += 1;
			l += 1;
		}
	}
	table[j] = '\0';
	*i = l;
	return (table);
}

char	*dollar(char *text, int *i, char **envp)
{
	char	*table;
	char	*dolar;

	table = creat_table(text, i);
	if (!ft_strlen(table))
		return (free(table), ft_strdup("$"));
	dolar = out_dollars(table, envp);
	return (free(table), dolar);
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
	key = ft_strjoin1(key, "=");
	while (env[i])
	{
		if (!ft_strncmp(key, env[i], ft_strlen1(key)))
			return (ft_substr(env[i], first_equale(env[i]), strlen(env[i]))); 
		i++;
	}
	return (ft_strdup(""));
}
