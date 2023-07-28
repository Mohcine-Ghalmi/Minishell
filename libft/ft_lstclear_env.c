/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleeps <sleeps@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:58:06 by mghalmi           #+#    #+#             */
/*   Updated: 2023/07/28 16:06:59 by sleeps           ###   ########.fr       */
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
		// if ((*lst)->key)
        	free((*lst)->key);
		// if((*lst)->value)
			free((*lst)->value);
        free(*lst);
		*lst = tmp;
	}
    free(*lst);
	free(tmp);
}

void	ft_lstclear_struct(t_data **lst)
{
	t_data	*tmp;

	if (!lst)
		return ;
	tmp = *lst;
	while (*lst)
	{
		tmp = (*lst)->next;
        // free((*lst)->av);
        free(*lst);
		*lst = tmp;
	}
    free(*lst);
	free(tmp);
}