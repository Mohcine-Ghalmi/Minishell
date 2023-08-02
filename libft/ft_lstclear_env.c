/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:58:06 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/02 11:16:12 by selhilal         ###   ########.fr       */
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
	free(*lst);
	free(tmp);
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
		free((*lst)->cmd);
		free(*lst);
		*lst = tmp;
	}
	free(*lst);
	free(tmp);
}
