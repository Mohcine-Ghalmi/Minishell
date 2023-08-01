/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:39:37 by selhilal          #+#    #+#             */
/*   Updated: 2023/07/18 19:39:37 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_token	*ft_lstnew(int type, char *str)
{
	t_token	*ptr;

	ptr = malloc(sizeof(t_token));
	if (!ptr)
		return (NULL);
	ptr->cmd = str;
	ptr->type = type;
	ptr->next = NULL;
	return (ptr);
}

t_token	*ft_lstlast(t_token	*lst)
{
	t_token	*tmp;

	tmp = lst;
	if (!tmp)
		return (NULL);
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

void	ft_back(t_token	**lst, t_token	*new)
{
	if (!new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	ft_lstlast(*lst)->next = new;
}

t_jointok	*ft_lstnew1(char *str, int type)
{
	t_jointok	*ptr;

	ptr = malloc(sizeof(t_jointok));
	if (!ptr)
		return (NULL);
	ptr->str = str;
	ptr->type = type;
	ptr->next = NULL;
	return (ptr);
}

t_jointok	*ft_lstlast1(t_jointok	*lst)
{
	t_jointok	*tmp;

	tmp = lst;
	if (!tmp)
		return (NULL);
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}
