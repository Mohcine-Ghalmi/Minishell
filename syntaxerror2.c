/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntaxerror2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 22:07:41 by selhilal          #+#    #+#             */
/*   Updated: 2023/07/09 15:53:54 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

int	qudes(char *str)
{
	int	i;
	int	ret;

	i = 0;
	ret = 2;
	while (str[i])
	{
		if (str[i] == '\"')
		{
			while (str[++i])
				if (str[i] == '\"')
					return (1);
			ret = 3;
		}
		if (str[i] == '\'')
		{
			while (str[++i])
				if (str[i] == '\'')
					return (1);
			ret = 3;
		}
		i++;
	}
	return (ret);
}

void	secend_syn(char *str, int i)
{
	while (str[i])
	{
		if (secend_syntax(str, i) == 0 || secend_syntax(str, i) == 5)
		{
			printf("syntax error near unexpected token `|'");
			exit(1);
		}
		else if (secend_syntax(str, i) == 2)
		{
			printf("syntax error near unexpected token `newline'");
			exit(1);
		}
		else if (secend_syntax(str, i) == 3)
		{
			printf("syntax error near unexpected token `>'");
			exit(1);
		}
		else if (secend_syntax(str, i) == 4)
		{
			printf("syntax error near unexpected token `<'");
			exit(1);
		}
		i++;
	}
}

void	parsing_token(char	*str)
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
		exit(1);
	}
	secend_syn(str, i);
	if (last_syntax(str[len]) == 2)
	{
		printf("syntax error near unexpected token `newline'");
		exit(1);
	}
	if (last_syntax(str[len]) == 3)
	{
		printf("syntax error near unexpected token `|'");
		exit(1);
	}
}
