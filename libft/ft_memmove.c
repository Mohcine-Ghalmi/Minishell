/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 23:59:05 by mghalmi           #+#    #+#             */
/*   Updated: 2023/07/12 23:59:07 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*dt;
	char	*sr;

	dt = (char *)dest;
	sr = (char *)src;
	if (!src && !dest)
		return (NULL);
	if (dt >= sr)
		while (len-- > 0)
			dt[len] = sr[len];
	else
		ft_memcpy(dt, sr, len);
	return ((void *)dt);
}
