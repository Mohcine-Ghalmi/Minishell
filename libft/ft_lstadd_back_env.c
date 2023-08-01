/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_env.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 23:09:20 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/01 19:12:07 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back_env(t_env **list, t_env *new)
{
	if (!*list)
	{
		*list = new;
		return ;
	}
	ft_lstlast_env(*list)->next = new;
}
