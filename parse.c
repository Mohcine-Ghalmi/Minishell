/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 00:35:58 by selhilal          #+#    #+#             */
/*   Updated: 2023/07/31 22:03:34 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

//void	checksyntax2(int type)
//{
//	if (type == 2 || type == 3 || type == 4 || type == 7 || type == 9)
//		ft_putstr_fd("syntax error near unexpected token `newline'\n", 2);
//}

void	message_error(int k)
{
	if (k == 1)
		ft_putstr_fd(" syntax error near unexpected token `|'\n", 2);
	else if (k == 2)
		ft_putstr_fd("syntax error near unexpected token `newline'\n", 2);
	else if (k == 3)
		ft_putstr_fd("syntax error near unexpected token `newline'\n", 2);
	else if (k == 4)
		ft_putstr_fd("syntax error near unexpected token `newline'\n", 2);
}

int	syntaxerror(t_jointok *token)
{
	t_jointok	*tmp;

	tmp = token;
	//checksyntax2(ft_lstlast1(tmp)->type);
	while (tmp)
	{
		if ((tmp->type == 4 && !tmp->next) || (tmp->type == 2 
				&& tmp->next->type == 4) || (tmp->type == 4
				&& tmp->next->type == 4 && tmp->next->next->type == 4)
			|| (tmp->type == 2 && tmp->next->type == 10
				&& tmp->next->next->type == 4) || (tmp->type == 3
				&& tmp->next->type == 10 && tmp->next->next->type == 4))
			return (message_error(1), 1);
		if ((tmp->type == 2 && tmp->next->type == 3)
			|| (tmp->type == 2 && tmp->next->type == 10
				&& tmp->next->type == 3))
			return (message_error(2), 1);
		if (tmp->type == 3 && tmp->next->type == 10
			&& tmp->next->type == 2)
			return (message_error(3), 1);
		if (tmp->type == 3 && tmp->next->type == 2)
			return (message_error(4), 1);
		if (tmp)
			tmp = tmp->next;
	}
	return (0);
}
