/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 21:04:01 by selhilal          #+#    #+#             */
/*   Updated: 2023/08/03 22:49:26 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_node	*new_node(char **cmd, int in, int out)
{
	t_node	*ptr;

	ptr = malloc(sizeof(t_node));
	if (!ptr)
		return (NULL);
	ptr->cmd = cmd;
	ptr->fdin = in;
	ptr->fdout = out;
	ptr->next = NULL;
	return (ptr);
}

t_node	*last_node(t_node	*lst)
{
	t_node	*tmp;

	tmp = lst;
	if (!tmp)
		return (NULL);
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

void	addnode_back(t_node	**lst, t_node	*new)
{
	if (!new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	last_node(*lst)->next = new;
}
