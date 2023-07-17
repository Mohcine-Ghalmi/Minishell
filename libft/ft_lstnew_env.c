/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleeps <sleeps@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 23:25:11 by mghalmi           #+#    #+#             */
/*   Updated: 2023/07/17 14:55:14 by sleeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_env	*ft_lstnew_env(char *key, char *value, int option)
{
	t_env	*new;

	new = (void *)malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	new->key = key;
    new->value = value;
	new->option = option;
	new->next = NULL;
	return (new);
}
