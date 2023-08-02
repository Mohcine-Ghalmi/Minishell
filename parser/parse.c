/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 00:35:58 by selhilal          #+#    #+#             */
/*   Updated: 2023/08/02 18:41:55 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	norm1(int k)
{
	if (k == 4 || k == 2 || k == 3 || k == 7 || k == 9)
		return (1);
	return (0);
}

int	syntaxerror(t_jointok	*token)
{
	t_jointok	*tmp;

	tmp = token;
	while (tmp)
	{
		if ((norm1(tmp->type) && !tmp->next)
			|| (norm1(tmp->type) && tmp->next
				&& norm1(tmp->next->type))
			|| (norm1(tmp->type)) && tmp->next
			&& tmp->next->type == 10 && tmp->next->next
			&& norm1(tmp->next->next->type))
		{
			s_fd("\033[31;1msyntax error\033[0m\n", 2);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}
