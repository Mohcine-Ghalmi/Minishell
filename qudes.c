/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qudes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 22:45:35 by selhilal          #+#    #+#             */
/*   Updated: 2023/07/12 22:54:29 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

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

int	qudes(char *str)
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
	if (yes == 1)
		return (0);
	if (yes == 2)
		return (0);
	return (1);
}

char	*dt_queds(char *str, int *i)
{
	char	*table[2];
	char	*ptr;
	char	b;
	int		j;

	b = str[*i];
	j = *i + 1;
	while (str[j] != b)
		j++;
	table[0] = ft_substr(str, 0, *i);
	table[1] = ft_substr(str, *i + 1, j - *i - 1);
	ptr = ft_strjoin(table[0], table[1]);
	*i = j - 2;
	table[0] = ft_strjoin(ptr, str + j + 1);
	str = ft_strdup(table[0]);
	free(table[0]);
	free(table[1]);
	return (str);
}

char	*rem_qudes(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		str = dt_queds(str, &i);
		i++;
	}
	return (str);
}

