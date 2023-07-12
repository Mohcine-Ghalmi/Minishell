/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:12:17 by selhilal          #+#    #+#             */
/*   Updated: 2023/07/12 21:42:07 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

t_token	*ft_lstnew(char	*str, int type)
{
	t_token	*ptr;

	ptr = (t_token *)malloc(sizeof(t_token));
	if (!ptr)
		return (NULL);
	ptr -> str = str;
	ptr ->type = type;
	ptr -> next = NULL;
	return (ptr);
}

t_token	*ft_lstlast(t_token	*lst)
{
	if (!lst)
		return (NULL);
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

t_node	*ft_lstnew2(t_node	*new)
{
	t_node	*ptr;

	ptr = (t_node *)malloc(sizeof(t_node));
	if (!ptr)
		return (NULL);
	ptr -> cmd = new->cmd;
	ptr -> outfile = new->outfile;
	ptr -> infile = new->infile;
	ptr -> append = new->append;
	ptr -> heredoc = new->heredoc;
	ptr -> next = NULL;
	return (ptr);
}

void	ft_lstadd_front(t_node	**lst, t_node	*new)
{
	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	new -> next = *lst;
	*lst = new;
}
