/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:31:15 by selhilal          #+#    #+#             */
/*   Updated: 2023/07/06 20:06:38 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

int	save_qotes(char *text, int i)
{
	int j = 0;
	int qotenum = 0;
	char	*new;

	while (text[i])
	{
		j = 0;
		if (text[i] == '\"')
		{
				j = i + 1;
				while (text[j] != '\"')
					j++;
		}
		if (text[i] == '\'')
		{
				j = i + 1;
				while (text[j] != '\'')
					j++;
		}
		
		i++;
	}
	return (j);
}

int operator(char *str)
{
	int i;

	i = 0; 
	while(str[i])
	{
		if(str[i] == '|' && str[i + 1] == '\0')
			return(PIPE);
		if(str[i] == '>' && str[i + 1] == '\0')
			return(IN);
		if(str[i] == '<' && str[i + 1] == '\0')
			return(OUT);
		if(str[i]== '>' && str[i + 1] == '>')
			return(APPEND);
		if(str[i] == '<' && str[i + 1] == '<')
			return(HEC);
		if(str[i] == '$' && str[i + 1] == '\0')
			return(DOLLAR);
		if(str[i] == '$' && str[i + 1] == '$') 
			return(DOBLE_DOL);
		else
			return(WORD);
		i++;
	}
	return(1);
}

void parsing(char *text)
{
	parsing_token(text);
	if(qudes(text) == 2)
	{
		printf("syntax error");
 		exit(1);
	}
}

int main(void)
{
	char	*text;
	t_token	*token;
	char *test;
	int 	i;
	int		j = 0;
	int		f = 0;
	token = NULL;
	while(1)
	{
		text = readline("> ");
		parsing(text);
		i = 0;
		while(text[i])
		{
			if(notword(text[i]) && !spaces(text[i]))
			{
				j = i;
				while (text[i] && notword(text[i]) && !spaces(text[i]))
					i++;
				f = i;
				test = ft_substr(text, j, f - j);
				ft_lstadd_back(&token, ft_lstnew(test,operator(test)));
			}
			if(!notword(text[i]) && !spaces(text[i]))
			{
				j = i;
				while (text[i] && !notword(text[i]) && !spaces(text[i]))
					i++;
					f = i;
					test = ft_substr(text, j, f - j);
				ft_lstadd_back(&token, ft_lstnew(test, operator(test)));
			}
			if(spaces(text[i]) && !notword(text[i]))
			{
				j = i;
				while (text[i] && !notword(text[i]) && spaces(text[i]))
					i++;
					f = i;
				ft_lstadd_back(&token, ft_lstnew(ft_substr(text, j, f - j), SPACE));
			}
		}
		//while(token->type != PIPE)
		//{
		//	printf("%s, %d\n",token->str, token->type);
		//	token = token->next;
		//}
	}
}
