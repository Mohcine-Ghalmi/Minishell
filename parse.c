/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 00:35:58 by selhilal          #+#    #+#             */
/*   Updated: 2023/07/26 21:36:55 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	checksyntax(t_jointok	*token)
{
	t_jointok	*tmp;

	tmp = token;
	if ((tmp)->type == 4)
		return (2);
	if (ft_lstlast1(tmp)->type == 2 || ft_lstlast1(tmp)->type == 3
		|| ft_lstlast1(tmp)->type == 4 || ft_lstlast1(tmp)->type == 7
		|| ft_lstlast1(tmp)->type == 9)
		return (3);
	while (tmp)
	{
		if (tmp->type == 2 && tmp->next->type == 4
			|| (tmp->type == 4 && tmp->next->type == 4
				&& tmp->next->next->type == 4)
			|| (tmp->type == 2 && tmp->next->type == 10
				&& tmp->next->next->type == 4)
			|| (tmp->type == 3 && tmp->next->type == 10
				&& tmp->next->next->type == 4))
			return (4);
		if ((tmp->type == 2 && tmp->next->type == 3)
			|| tmp->type == 2 && tmp->next->type == 10 && tmp->next->type == 3)
			return (5);
		if (tmp->type == 3 && tmp->next->type == 10 && tmp->next->type == 2)
			return (6);
		if (tmp->type == 3 && tmp->next->type == 2)
			return (7);
		tmp = tmp->next;
	}
	return (1);
}

void	syntaxerror(t_jointok *token)
{
	t_jointok	*tmp;

	tmp = token;
	if (checksyntax(tmp) == 2 || checksyntax(tmp) == 4)
		printf("syntax error near unexpected token `|'\n");
	if (checksyntax(tmp) == 3 || checksyntax(tmp) == 7)
		printf("syntax error near unexpected token `newline'\n");
	if (checksyntax(tmp) == 5)
		printf("syntax error near unexpected token `<'\n");
	if (checksyntax(tmp) == 6)
		printf("syntax error near unexpected token `>'\n");
}
