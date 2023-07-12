/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 02:09:57 by selhilal          #+#    #+#             */
/*   Updated: 2023/07/12 01:48:11 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1)
		s1 = ft_strdup("");
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 2));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i])
			str[i] = s1[i];
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[ft_strlen(s1) + ft_strlen(s2) + 1] = '\0';
	free(s1);
	free(s2);
	return (str);
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
