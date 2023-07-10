/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:31:15 by selhilal          #+#    #+#             */
/*   Updated: 2023/07/10 11:38:32 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

int	operator(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '|' && str[i + 1] == '\0')
			return (PIPE);
		if (str[i] == '>' && str[i + 1] == '\0')
			return (IN);
		if (str[i] == '<' && str[i + 1] == '\0')
			return (OUT);
		if (str[i] == '>' && str[i + 1] == '>')
			return (APPEND);
		if (str[i] == '<' && str[i + 1] == '<')
			return (HEC);
		if (str[i] == '$' && str[i + 1] == '\0')
			return (DOLLAR);
		if (str[i] == '$' && str[i + 1] == '$') 
			return (DOBLE_DOL);
		if (str[i] == '$' && ft_isalnum(str[i + 1]))
			return (VAR);
		else
			return (WORD);
		i++;
	}
	return (1);
}

void	parsing(char *text)
{
	parsing_token(text);
	if (qudes(text) == 3)
	{
		printf("syntax error");
		exit(1);
	}
}

char	*make_spaces(char *tst)
{
	char	*text;
	int		t;
	int		n;
	int		replace;

	n = 0;
	t = 0;
	while (tst[t])
	{
		n++;
		if (tst[t] == ' ')
		{
			if (notword(tst[t + 1]))
				n--;
		}
		t++;
	}
	text = malloc(n);
	t = 0;
	n = 0;
	replace = 1;
	while (tst[t])
	{
		replace = 1;
		if (spaces(tst[t]))
		{
			if (notword(tst[t + 1]))
				replace = 0;
			else
				replace = 1;
		}
		if (replace == 1)
			text[n++] = tst[t];
		t++;
	}
	text[n] = '\0';
	return (text);
}

int	main(void)
{
	char	*text;
	t_token	*token;
	char	*tst;
	char	*test;
	int		i;
	int		j;
	int		f;

	j = 0;
	f = 0;
	token = NULL;
	while (1)
	{
		tst = readline("> ");
		parsing(tst);
		text = make_spaces(tst);
		text = rem_qudes(text);
		while (text[i])
		{
			if (notword(text[i]))
			{
				j = i;
				while (text[i] && notword(text[i]))
					i++;
				f = i;
				test = ft_substr(text, j, f - j);
				ft_lstadd_back(&token, ft_lstnew(test, operator(test)));
			}
			if (!notword(text[i]))
			{
				j = i;
				while (text[i] && !notword(text[i]))
					i++;
					f = i;
					test = ft_substr(text, j, f - j);
				ft_lstadd_back(&token, ft_lstnew(test, operator(test)));
			}
		}
		while (token)
		{
			printf("%s,%d\n", token->str, token->type);
				token = token->next;
		}
	}
}
