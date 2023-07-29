/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 00:35:58 by selhilal          #+#    #+#             */
/*   Updated: 2023/07/29 10:50:07 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

int	checksyntax(t_token *tmp)
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
	return (1);
}

int	checksyntax1(int type)
{
	if (type == 4)
		return (2);
	return (0);
}

int	checksyntax2(int type)
{
	if (type == 2 || type == 3 || type == 4 || type == 7 || type == 9)
		return (3);
	return (0);
}

void	syntaxerror(t_jointok	*token)
{
	t_jointok	*tmp;

	tmp = token;
	if (checksyntax1(tmp->type) == 2)
		ft_putstr_fd("syntax error near unexpected token `|'\n", 2);
	if (checksyntax2(ft_lstlast1(tmp)->type) == 3)
		ft_putstr_fd("syntax error near unexpected token `newline'\n", 2);
	//while (tmp)
	//{
	//	if (checksyntax(&tmp) == 2)
	//		ft_putstr_fd("syntax error near unexpected token `|'\n", 2);
	//	if (checksyntax(&tmp) == 7)
	//		ft_putstr_fd("syntax error near unexpected token `newline'\n", 2);
	//	if (checksyntax(&tmp) == 5)
	//		ft_putstr_fd("syntax error near unexpected token `<'\n", 2);
	//	if (checksyntax(&tmp) == 6)
	//		ft_putstr_fd("syntax error near unexpected token `>'\n", 2);
	//	tmp = tmp->next;
	//}
}
