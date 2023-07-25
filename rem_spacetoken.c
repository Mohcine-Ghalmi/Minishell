/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rem_spacetoken.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:33:25 by selhilal          #+#    #+#             */
/*   Updated: 2023/07/25 13:33:25 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lsttoken	*new_ltoken(char *str, int type)
{
	t_lsttoken	*ptr;

	ptr = malloc(sizeof(t_lsttoken));
	if (!ptr)
		return (NULL);
	ptr->str = str;
	ptr->type = type;
	ptr->next = NULL;
	return (ptr);
}

t_lsttoken	*last_ltoken(t_lsttoken	*lst)
{
	t_lsttoken	*tmp;

	tmp = lst;
	if (!tmp)
		return (NULL);
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

void	addnode_ltoken(t_lsttoken	**lst, t_lsttoken	*new)
{
	if (!new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	last_ltoken(*lst)->next = new;
}

t_lsttoken	*ltoken(t_jointok **token)
{
	t_jointok	*tmp;
	t_lsttoken	*lst;

	lst = NULL;
	tmp = *token;
	while (tmp)
	{
		if (tmp->next == NULL && tmp->type == 10)
			tmp = NULL;
		else if (tmp->type == 10 && tmp->next)
			tmp = tmp->next;
		else
		{
			addnode_ltoken(&lst, new_ltoken(tmp->str, tmp->type));
			if (tmp)
				tmp = tmp->next;
		}
	}
	return (lst);
}
