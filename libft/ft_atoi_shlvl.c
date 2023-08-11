/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_shlvl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:00:26 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/11 14:11:04 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long	ft_atoi_shlvl(char *str)
{
	unsigned long long	res;
	unsigned long long	i;
	unsigned long long	signe;

	res = 0;
	i = 0;
	signe = 1;
	if (!str)
		return (0);
	while (str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r'
		|| str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + str[i++] - '0';
	if (str[i])
		res = 0;
	return (signe * res);
}
