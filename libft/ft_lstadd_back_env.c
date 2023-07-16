/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_env.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleeps <sleeps@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 23:09:20 by mghalmi           #+#    #+#             */
/*   Updated: 2023/07/16 18:41:51 by sleeps           ###   ########.fr       */
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
	ft_lstlast(*list)->next = new;
}
