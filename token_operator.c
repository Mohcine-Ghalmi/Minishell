/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_operator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 22:39:07 by selhilal          #+#    #+#             */
/*   Updated: 2023/07/12 22:54:23 by selhilal         ###   ########.fr       */
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
		if (str[i] == '$' && ft_isalnum(str[i + 1]))
			return (VAR);
		else
			return (WORD);
		i++;
	}
	return (1);
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