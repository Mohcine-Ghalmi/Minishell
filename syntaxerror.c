/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntaxerror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 19:38:51 by selhilal          #+#    #+#             */
/*   Updated: 2023/07/20 19:38:51 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

int	checksyntax(t_jointok	*token)
{
	t_jointok	*tmp;

	tmp = token;
	if ((tmp)->type == 4)
		return (2);
	if(ft_lstlast1(tmp)->type == 2 || ft_lstlast1(tmp)->type == 3
		|| ft_lstlast1(tmp)->type == 4 ||ft_lstlast1(tmp)->type == 7
		|| ft_lstlast1(tmp)->type == 9)
		return(3);
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
		
			tmp = tmp->next;
	}
	return (1);
}
