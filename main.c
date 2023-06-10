/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:31:15 by selhilal          #+#    #+#             */
/*   Updated: 2023/06/10 14:32:41 by selhilal         ###   ########.fr       */
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

int	secend_syntax(char *str, int i, t_lexer *token)
{
	while (str[i])
	{
		if (str[i] == token->in && str[i + 2] == token->pipe
			|| str[i] == token->out && str[i + 2] == token->pipe)
			return (0);
		if (str[i] == token->pipe && str[i + 2] == token->in
			||str[i] == token->pipe && str[i + 2] == token->out)
			return (2);
		i++;
	}
	return (1);
}

int	last_syntax(char c, t_lexer *token)
{
	if (c == token->in || c == token->out)
		return (0);
	return (1);
}

//void splite_cmnd(char *str)
//{
//	int i;
//	i = 0;
//	while(str[i])
//	{
//		if(str[i])
//			splite();
//	}
//}

void	parsing_token(char *str, t_lexer *token)
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
		if (secend_syntax(str, i, token) == 0)
		{
			printf("syntax error near unexpected token `|'");
			exit(1);
		}
		else if(secend_syntax(str, i, token) == 2)
		{
			printf("syntax error near unexpected token `newline'");
			exit(1);
		}
		i++;
	}
		if (last_syntax(str[len], token) == 0)
		{
			printf("syntax error near unexpected token `newline'");
			exit(1);
		}
	
}


void	ft_token(char *str, t_lexer *token)
{
	int		i;

	i = 0;
	if (!token)
		return ;
	while (str[i])
	{
		if (str[i] == '|')
			token->pipe = str[i];
		else if (str[i] == '>' && str[i + 1] == '>')
		{
			token->append[0] = str[i];
			token->append[1] = str[i + 1];
			i++;
		}
		else if (str[i] == '>')
			token->in = str[i];
		else if (str[i] == '<')
			token->out = str[i];
		else if (str[i] == '$')
			token->dollar = str[i];
		i++;
	}
}

int	main(void)
{
	t_lexer	*token;
	char	*text;

	token = malloc(sizeof(t_lexer));
	text = readline("$ ");
	ft_token(text, token);
	parsing_token(text, token);
	return (0);
}
