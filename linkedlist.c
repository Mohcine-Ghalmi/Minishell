/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:12:17 by selhilal          #+#    #+#             */
/*   Updated: 2023/07/06 17:13:06 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

t_token	*ft_lstnew(char	*str)
{
	t_token	*ptr;

	ptr = (t_token *)malloc(sizeof(t_token));
	if (!ptr)
		return (NULL);
	ptr -> str = str;
	ptr -> next = NULL;
	return (ptr);
}

t_token	*ft_lstlast(t_token	*lst)
{
	if (!lst)
	{
		puts("kds");
		return (NULL);
	}
	while (lst ->next != NULL)
		lst = lst ->next;
	return (lst);
}

void	ft_lstadd_back(t_token	**lst, t_token	*new)
{
	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ft_lstlast(*lst)->next = new;
}
