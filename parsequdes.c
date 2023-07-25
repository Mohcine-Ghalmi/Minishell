/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsequdes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 19:41:37 by selhilal          #+#    #+#             */
/*   Updated: 2023/07/20 19:41:37 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

void	strqudes(int *yes, int c)
{
	if (c == '\'')
	{
		if (*yes == 1)
			*yes = 0;
		else if (*yes == 0)
			*yes = 1;
	}
	if (c == '\"')
	{
		if (*yes == 2)
			*yes = 0;
		else if (*yes == 0)
			*yes = 2;
	}
}

int	qudespars(char *str)
{
	int	i;
	int	yes;

	i = 0;
	yes = 0;
	while (str[i])
	{
		strqudes(&yes, str[i]);
		i++;
	}
	if (yes == 1 || yes == 2)
		return (0);
	return (1);
}
