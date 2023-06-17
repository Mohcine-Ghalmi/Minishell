/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:47:25 by selhilal          #+#    #+#             */
/*   Updated: 2023/06/12 13:39:55 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

char	*ft_strdup(char *string)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char *)malloc(sizeof(char) * strlen(string) + 1);
	if (!ptr)
		return (NULL);
	while (string[i])
	{
		ptr[i] = string[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1)
		s1 = ft_strdup("");
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * ((strlen(s1) + strlen(s2)) + 2));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i])
			str[i] = s1[i];
	str[i++] = ' ';
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[strlen(s1) + strlen(s2) + 1] = '\0';
	free(s1);
	return (str);
}