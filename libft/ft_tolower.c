/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:50:35 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/02 11:13:52 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}

char	*ft_tolower_str(char *str)
{
	int		i;
	char	*new;

	new = malloc(ft_strlen1(str) + 1);
	i = 0;
	while (str[i])
	{
		new[i] = ft_tolower(str[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
