/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:58:06 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/08 20:26:10 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear_env(t_env **lst)
{
	t_env	*tmp;

	if (!lst)
		return ;
	tmp = *lst;
	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->key);
		free((*lst)->value);
		free(*lst);
		*lst = tmp;
	}
	free((*lst)->key);
	free((*lst)->value);
	free(*lst);
	free(tmp);
	*lst = NULL;
}

void	ft_lstclear_struct(t_node **lst)
{
	t_node	*tmp;

	if (!lst)
		return ;
	tmp = *lst;
	while (*lst)
	{
		tmp = (*lst)->next;
		free_double((*lst)->cmd);
		free(*lst);
		*lst = tmp;
	}
	free_double((*lst)->cmd);
	free(*lst);
	free(tmp);
}
