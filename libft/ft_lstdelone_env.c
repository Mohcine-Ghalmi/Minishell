/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 15:08:25 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/02 11:16:37 by selhilal         ###   ########.fr       */
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
