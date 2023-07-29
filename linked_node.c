/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 21:04:01 by selhilal          #+#    #+#             */
/*   Updated: 2023/07/28 22:04:39 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

t_node	*new_node(char **cmd, int in, int out)
{
	t_node	*ptr;

	ptr = malloc(sizeof(t_node));
	if (!ptr)
		return (NULL);
	ptr->cmd = cmd;
	ptr->fdin = in;
	ptr->fdin = out;
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
