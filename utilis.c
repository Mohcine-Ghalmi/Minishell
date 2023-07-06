/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:11:59 by selhilal          #+#    #+#             */
/*   Updated: 2023/07/06 17:40:47 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

int	notword(int c)
{
	if (c == '|' || c == '>' || c == '<')
		return (1);
	return (0);
}

int spaces(int c)
{
	if(c == '\t' || c == '\v' || c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

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
	ptr = ft_strdup("");
	return (ptr);
}