/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:50:35 by mghalmi           #+#    #+#             */
/*   Updated: 2023/07/13 17:52:34 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
	c += 32;
	return (c);
}

void    ft_tolower_str(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        str[i] = ft_tolower(str[i]);
        i++;
    }
}
