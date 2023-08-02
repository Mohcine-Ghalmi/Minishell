/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:25:35 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/02 11:46:32 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *htack, const char *needle, size_t len)
{
	size_t	i;
	size_t	pos;

	if (!htack && len == 0)
		return (NULL);
	if (!*needle)
		return ((char *)htack);
	i = 0;
	while (htack[i] && i < len)
	{
		if (htack[i] == needle[0])
		{
			pos = 1;
			while (needle[pos] && htack[i + pos] == needle[pos]
				&& pos + i < len)
				pos++;
			if (needle[pos] == '\0')
				return ((char *)&htack[i]);
		}
		i++;
	}
	return (0);
}
