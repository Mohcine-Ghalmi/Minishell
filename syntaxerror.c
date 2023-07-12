/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntaxerror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:18:35 by selhilal          #+#    #+#             */
/*   Updated: 2023/07/12 22:51:34 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

int	first_syntax(char c)
{
	if (c == '|')
		return (0);
	return (1);
}

int	secend_syntax(char *str, int i)
{
	while (str[i])
	{
		if (str[i] == '>' && str[i + 2] == '|'
			|| str[i] == '<' && str[i + 2] == '|')
			return (2);
		if (str[i] == '>' && str[i + 1] == '|'
			|| str[i] == '<' && str[i + 1] == '|')
			return (2);
		if (str[i] == '>' && str[i + 2] == '>')
			return (3);
		if (str[i] == '<' && str[i + 2] == '<')
			return (4);
		if (str[i] == '|' && str[i + 2] == '|')
			return (5);
			i++;
	}
	return (1);
}

int	last_syntax(char c)
{
	if (c == '>' || c == '<')
		return (2);
	if (c == '|')
		return (3);
	return (1);
}

int	ft_strchr(const char *str, int c, int i)
{
	while (str[i])
	{
		if (str[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}
