/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 00:35:58 by selhilal          #+#    #+#             */
/*   Updated: 2023/08/02 13:37:42 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	message_error(int k)
{
	if (k == 1)
		s_fd("\033[31;1msyntax error near unexpected token`|'\033[0m\n", 2);
	if (k == 2)
		s_fd("\033[31;1msyntax error near unexpected token `<'\033[0m\n", 2);
	if (k == 3)
		s_fd("\033[31;1msyntax error near unexpected token `>'\033[0m\n", 2);
	if (k == 4)
		s_fd("\033[31;1msyntax error near unexpected token `>>'\033[0m\n", 2);
	if (k == 5)
		s_fd("\033[31;1msyntax error near unexpected token `<<'\033[0m\n", 2);
	if (k == 6)
		s_fd("\033[31;1msyntax error near unexpected token`newline'\033[0m\n", 2);
	if (k == 7)
		s_fd("\033[31;1msyntax error near unexpected token `||'\033[0m\n", 2);
}

int	norm1(int k)
{
	if (k == 2 || k == 3 || k == 7 || k == 9)
		return (1);
	return (0);
}

int	norm2(int k)
{
	if (k == 2 || k == 3 || k == 7 || k == 9)
		return (1);
	return (0);
}

int	norm3(int k)
{
	if (k == 2 || k == 3 || k == 7 || k == 9)
		return (1);
	return (0);
}

int	syntaxerror(t_jointok *token)
{
	t_jointok	*tmp;

	tmp = token;
	while (tmp)
	{
		if (norm1(tmp->type) && !tmp->next)
			return (message_error(6), 1);
		if ((tmp->type == 4 && !tmp->next) || (norm1(tmp->type)
				&& tmp->next->type == 4) || (tmp->type == 4
				&& tmp->next->type == 4 && tmp->next->next
				&& tmp->next->next->type == 4)
			|| (norm1(tmp->type) && (tmp->next->type == 10
					&& tmp->next->next && tmp->next->next->type == 4)))
			return (message_error(1), 1);
		if ((norm2(tmp->type) && tmp->next->type == 2)
			|| ((norm2(tmp->type)) && (tmp->next->next->type == 10
					&& tmp->next->next && tmp->next->type == 2)) 
			|| (tmp->type == 2 && tmp->next->type == 10 && tmp->next->next
				&& norm2(tmp->next->next->type)))
			return (message_error(2), 1);
		if ((norm3(tmp->type) && tmp->next->type == 10
				&& tmp->next->next && tmp->next->next->type == 3)
			|| (norm3(tmp->type) && tmp->next->type == 3)
			|| (tmp->type == 3 && tmp->next->type == 10 && tmp->next->next
				&& norm3(tmp->next->next->type)))
			return (message_error(3), 1);
		if (((tmp->type == 2 || tmp->type == 3) && tmp->next->type == 7)
			|| ((tmp->type == 2 || tmp->type == 3) && tmp->next->type == 10
				&& tmp->next->next->type == 7))
			return (message_error(4), 1);
		if (((tmp->type == 2 || tmp->type == 3) && tmp->next->type == 9)
			|| ((tmp->type == 2 || tmp->type == 3) && tmp->next->type == 10
				&& tmp->next->next->type == 9))
			return (message_error(5), 1);
		if (tmp->type == 4 && tmp->next->type == 4)
			return (message_error(7), 1);
		if (tmp->type == 4 && tmp->next->type == 4)
			return (message_error(7), 1);
		if (tmp)
			tmp = tmp->next;
	}
	return (0);
}
