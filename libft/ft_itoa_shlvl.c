/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_shlvl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:01:34 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/08 08:45:53 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long	len_int(unsigned long long n)
{
	unsigned long long	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa_shlvl(unsigned long long n)
{
	unsigned long long		len;
	unsigned long long		i;
	char					*res;

	i = 0;
	len = len_int(n);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (n < 0)
	{
		res[0] = '-';
		i = 1;
	}
	while (len-- > i)
	{
		if (n < 0)
			res[len] = '0' + n % 10 * (-1);
		else
			res[len] = '0' + n % 10;
		n = n / 10;
	}
	return (res);
}
