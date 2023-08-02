/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 02:06:48 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/02 11:16:46 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_env	*ft_lstlast_env(t_env *lst)
{
	if (lst)
	{
		while (lst && lst->next)
			lst = lst->next;
	}
	return (lst);
}
