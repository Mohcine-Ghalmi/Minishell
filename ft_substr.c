/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:55:24 by selhilal          #+#    #+#             */
/*   Updated: 2023/07/10 17:03:38 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

size_t	ft_strlen1(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *string)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char *)malloc(sizeof(char) * ft_strlen1(string)+1);
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

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	if (!s)
		return (NULL);
	if (start < ft_strlen1(s))
	{
		if ((ft_strlen1(s) - start) < len)
			ptr = malloc(ft_strlen1(s) - start + 1);
		else
			ptr = malloc(len + 1);
		if (!ptr)
			return (NULL);
		i = -1;
		while (++i < len && s[start])
			ptr[i] = s[start++];
		ptr[i] = 0;
		return (ptr);
	}
	return (ptr);
}
