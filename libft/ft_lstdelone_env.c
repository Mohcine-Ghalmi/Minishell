/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 15:08:25 by mghalmi           #+#    #+#             */
/*   Updated: 2023/07/21 15:40:41 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_env *lst)
{
	if (!lst)
		return ;
    if (lst->key)
	    free(lst->key);
    if (lst->value)
        free(lst->value);
	free(lst);
}