/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntaxerror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:18:35 by selhilal          #+#    #+#             */
/*   Updated: 2023/07/06 18:27:47 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

int	ft_strlen(char *str)
 {
 	int	i;

 	i = 0;
 	while (str[i])
 		i++;
 	return (i);
 }

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
 			return (1);
 		if (str[i] == '|' && str[i + 2] == '>'
 			||str[i] == '|' && str[i + 2] == '<')
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
 	if(c == '|')
 		return (3);
 	return(1);
 }


 int	ft_strchr(const char *str, int c)
 {
 	int j;
 	int i;
 	i = 0;
 	j = 0;
 	while (str[i])
 	{
 		if (str[i] == (char)c)
 			j++;
 		i++;
 	}
 	if (str[i] == (char)c)
 		j++;
 	return (j);
 }

 int qudes(char *str)
 {
 	int i;

 	i = 0;
 	while(str[i])
 	{
 		if(str[i] == '\"')
 		{
 			i++;
 			if(ft_strchr(str, '\"') % 2 != 0)
 				return(2);
 		}
 		if(str[i] == '\'')
 		{
 			i++;
 			if(ft_strchr(str, '\'') % 2 != 0)
 				return(2);
 		}
 		i++;
 	}
 	return(1);
 }
 
 void	parsing_token(char *str)
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
 	while (str[i])
 	{
 		if (secend_syntax(str, i) == 0 || secend_syntax(str, i) == 5)
 		{
 			printf("syntax error near unexpected token `|'");
 			exit(1);
 		}
 		else if(secend_syntax(str, i) == 2)
 		{
 			printf("syntax error near unexpected token `newline'");
 			exit(1);
 		}
 		else if(secend_syntax(str, i) == 3)
 		{
 			printf("syntax error near unexpected token `>'");
 			exit(1);
 		}
 		else if(secend_syntax(str, i) == 4)
 		{
 			printf("syntax error near unexpected token `<'");
 			exit(1);
 		}
 		i++;
 	}
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
