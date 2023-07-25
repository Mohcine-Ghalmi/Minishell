/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expande.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 20:17:25 by selhilal          #+#    #+#             */
/*   Updated: 2023/07/25 15:09:32 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

int dollar_length(char *text, int i, t_token **token)
{
	int		l;
	int 	j;

	j = 0;
	l =  i + 1;
	while (text[l] && ft_isalnum(text[l]) && !spaces(text[l]))
	{
		j += 1;
		l += 1;
	}
	return (l);
}

char	*dollar(char *text, int *i, t_token **token,char **envp)
{
	char	*table;
	char	*dolar;
	int		l;

	dolar = ft_strdup("");
	*i += 1;
	l = 0;
	table = malloc(dollar_length(text, *i, token));
	while (text[*i] && ft_isalnum(text[*i]) && !spaces(text[*i]))
	{
		table[l] = text[*i];
		l += 1;
		*i += 1;
	}
	table[l] = '\0';
	dolar = out_dollars(table, envp);
	return (dolar);
}

char	*out_dollars(char *key, char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (!strncmp(key, env[i], strlen(key)))
			return (ft_substr(env[i], strlen(key) + 1, strlen(env[i])));
		i++;
	}
	return (ft_strdup(""));
}
