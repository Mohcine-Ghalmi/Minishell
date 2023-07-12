/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 22:11:53 by selhilal          #+#    #+#             */
/*   Updated: 2023/07/12 22:13:38 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

void	my_token(t_token **token, char *text)
{
	int		i;
	int		j;
	int		f;
	char	*test;

	i = 0;
	j = 0;
	f = 0;
	while (text[i])
	{
		if (notword(text[i]))
		{
			j = i;
			while (text[i] && notword(text[i]))
				i++;
				f = i;
				test = ft_substr(text, j, f - j);
			ft_lstadd_back(token, ft_lstnew(test, operator(test)));
		}
		if (!notword(text[i]))
		{
			j = i;
			while (text[i] && !notword(text[i]))
				i++;
				f = i;
				test = ft_substr(text, j, f - j);
			ft_lstadd_back(token, ft_lstnew(test, operator(test)));
		}
	}
}
