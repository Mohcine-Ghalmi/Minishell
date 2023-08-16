/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_shlvl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:00:26 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/17 00:40:13 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoi_shlvl(char *str)
{
	long long	res;
	long long	i;
	long long	signe;

	res = 0;
	i = 0;
	signe = 1;
	if (!str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (res > res * 10 + str[i] - '0')
			return (9223372036854775807);
		res = res * 10 + str[i++] - '0';
	}
	if (str[i])
		res = 0;
	return (signe * res);
}
