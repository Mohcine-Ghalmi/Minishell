/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expande.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 20:17:25 by selhilal          #+#    #+#             */
/*   Updated: 2023/07/29 22:39:09 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

int	dollar_length(char *text, int i, t_token **token)
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

char	*creat_table(char *text, int *i, t_token **token)
{
	int		l;
	int		j;
	char	*table;

	j = 0;
	l = *i + 1;
	table = calloc(1, dollar_length(text, *i, token));
	while (text[l] && ft_isalnum(text[l]) && text[l] != '$')
	{
		table[j] = text[l];
		j += 1;
		l += 1;
	}
	table[j] = '\0';
	*i = l;
	return (table);
}

char	*dollar(char *text, int *i, t_token **token, char **envp)
{
	char	*table;
	char	*dolar;

	dolar = ft_strdup("");
	table = creat_table(text, i, token);
	if (!ft_strlen(table))
		return (free(table), ft_strdup(""));
	dolar = out_dollars(table, envp);
	printf("dolar = %s\n", dolar);
	return (free(table), dolar);
}

int	ft_strncmp(char *str1, char *str2, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
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
	while (env[i])
	{
		if (!ft_strncmp(key, env[i], strlen(key)))
			return (ft_substr(env[i], strlen(key) + 1, strlen(env[i])));
		i++;
	}
	return (ft_strdup(""));
}
