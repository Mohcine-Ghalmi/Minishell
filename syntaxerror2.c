/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntaxerror2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 22:07:41 by selhilal          #+#    #+#             */
/*   Updated: 2023/07/10 18:21:49 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

void	strqudes(int *yes, int c)
{
	if (c == '\'')
	{
		if (*yes == 1)
			*yes = 0;
		else if (*yes == 0)
			*yes = 1;
	}
	if (c == '\"')
	{
		if (*yes == 2)
			*yes = 0;
		else if (*yes == 0)
			*yes = 2;
	}
}

int	qudes(char *str)
{
	int	i;
	int	yes;

	i = 0;
	yes = 0;
	while (str[i])
	{
		strqudes(&yes, str[i]);
		i++;
	}
	if (yes == 1)
		return (0);
	if (yes == 2)
		return (0);
	return (1);
}

int	secend_syn(char *str, int i)
{
	while (str[i])
	{
		if (secend_syntax(str, i) == 0 || secend_syntax(str, i) == 5)
		{
			printf("syntax error near unexpected token `|'");
			return (0);
		}
		else if (secend_syntax(str, i) == 2)
		{
			printf("syntax error near unexpected token `newline'");
			return (0);
		}
		else if (secend_syntax(str, i) == 3)
		{
			printf("syntax error near unexpected token `>'");
			return (0);
		}
		else if (secend_syntax(str, i) == 4)
		{
			printf("syntax error near unexpected token `<'");
			return (0);
		}
		i++;
	}
	return (1);
}

int	parsing_token(char	*str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str) - 1;
	while (str[i] == ' ')
		i++;
	if (!first_syntax(str[i]))
	{
		printf("syntax error near unexpected token `|'");
		return (0);
	}
	secend_syn(str, i);
	if (last_syntax(str[len]) == 2)
	{
		printf("syntax error near unexpected token `newline'");
		return (0);
	}
	else if (last_syntax(str[len]) == 3)
	{
		printf("syntax error near unexpected token `|'");
		return (0);
	}
	return (1);
}
