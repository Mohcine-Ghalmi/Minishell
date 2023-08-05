/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 00:35:58 by selhilal          #+#    #+#             */
/*   Updated: 2023/08/05 06:08:12 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	norm1(int k)
{
	if (k == 4 || k == 2 || k == 3 || k == 7 || k == 9)
		return (1);
	return (0);
}

int	norm2(int k)
{
	if (k == 2 || k == 4 || k == 3 || k == 7)
		return (1);
	return (0);
}

int	syntaxerror(t_jointok *token)
{
	t_jointok	*tmp;

	tmp = token;
	if (tmp->type == 4)
	{
		s_fd("\033[31;1msyntax error\033[0m\n", 2);
		return (1);
	}
	while (tmp)
	{
		if ((norm1(tmp->type) && tmp->next && tmp->next->type == 10
				&& !tmp->next->next)
			|| (norm1(tmp->type) && !tmp->next)
			|| (norm2(tmp->type) && tmp->next
				&& norm2(tmp->next->type))
			|| ((norm2(tmp->type) && tmp->next
					&& tmp->next->type == 10 && tmp->next->next
					&& norm2(tmp->next->next->type))))
			return (s_fd("\033[31;1msyntax error\033[0m\n", 2), 1);
		if (tmp)
			tmp = tmp->next;
	}
	return (0);
}
