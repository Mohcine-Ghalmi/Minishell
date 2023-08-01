/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:40:21 by selhilal          #+#    #+#             */
/*   Updated: 2023/07/18 19:40:21 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

// size_t	ft_strlen1(char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i])
// 	{
// 		i++;
// 	}
// 	return (i);
// }

// char	*ft_strdup(char *string)
// {
// 	int		i;
// 	char	*ptr;

// 	i = 0;
// 	ptr = (char *)malloc(sizeof(char) * ft_strlen1(string)+1);
// 	if (!ptr)
// 	{
// 		free(ptr);
// 		return (NULL);
// 	}
// 	while (string[i])
// 	{
// 		ptr[i] = string[i];
// 		i++;
// 	}
// 	ptr[i] = '\0';
// 	return (ptr);
// }

// char	*ft_substr(char *s, int start, int len)
// {
// 	char	*ptr;
// 	int		i;

// 	if (!s)
// 		return (NULL);
// 	if (start < ft_strlen(s))
// 	{
// 		if ((ft_strlen(s) - start) < len)
// 			ptr = malloc(ft_strlen(s) - start + 1);
// 		else
// 			ptr = malloc(len + 1);
// 		if (!ptr)
// 			return (NULL);
// 		i = -1;
// 		while (++i < len && s[start])
// 			ptr[i] = s[start++];
// 		ptr[i] = 0;
// 		return (ptr);
// 	}
// 	ptr = ft_strdup("");
// 	return (ptr);
// }
