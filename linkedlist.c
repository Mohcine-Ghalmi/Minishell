/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:12:17 by selhilal          #+#    #+#             */
/*   Updated: 2023/07/06 20:01:14 by selhilal         ###   ########.fr       */
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

t_node	*ft_lstnew2(char	*cmd, char *out, char *in)
{
	t_node	*ptr;

	ptr = (t_node *)malloc(sizeof(t_node));
	if (!ptr)
		return (NULL);
	ptr -> cmd = cmd;
	ptr -> outfile = out;
	ptr -> infile = in;
	ptr -> next = NULL;
	return (ptr);
}

void	ft_lstadd_back2(t_node	**lst, t_node	*new)
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
