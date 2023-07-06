/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:31:15 by selhilal          #+#    #+#             */
/*   Updated: 2023/07/06 17:12:39 by selhilal         ###   ########.fr       */
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

int main(void)
{
	char	*text;
	t_token	*token;
	int 	i;
	int		j = 0;
	int		f = 0;
	token = malloc(sizeof(t_token));

	while(1)
	{
		text = readline("> ");
		i = 0;
		while(text[i])
		{
			if(notword(text[i]))
			{
				j = i;
				while (text[i] && notword(text[i]))
					i++;
				f = i;
				ft_lstadd_back(&token, ft_lstnew(ft_substr(text, j, f - j)));
			}
			if(!notword(text[i]))
			{
				j = i;
				while (text[i] && !notword(text[i]))
					i++;
					f = i;

				ft_lstadd_back(&token, ft_lstnew(ft_substr(text, j, f - j)));
			}
		}
		while(token)
		{
			printf("%s\n",token->str);
			token = token->next;
		}
	}
}
