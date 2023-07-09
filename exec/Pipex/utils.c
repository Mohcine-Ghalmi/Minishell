/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:26:48 by mghalmi           #+#    #+#             */
/*   Updated: 2023/01/23 15:34:42 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*path_join(char *path, char *bin)
{
	char	*joined;
	int		i;
	int		j;
	int		len;

	len = ft_strchr1(path, 0) + ft_strchr1(bin, 0);
	joined = malloc(sizeof(char) * (len + 2));
	i = 0;
	j = 0;
	while (path[j])
		joined[i++] = path[j++];
	joined[i++] = '/';
	j = 0;
	while (bin[j])
		joined[i++] = bin[j++];
	joined[i] = 0;
	return (joined);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	if (n == 0)
		return (0);
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (str1[i] && str2[i] && str1[i] == str2[i] && --n)
		++i;
	return (str1[i] - str2[i]);
}

char	*ft_strdup1(char *str, unsigned int n)
{
	char				*duped;
	unsigned int		i;

	i = 0;
	duped = malloc(sizeof(char) * (n + 1));
	while (i < n)
		duped[i++] = *str++;
	duped[n] = 0;
	return (duped);
}

int	ft_strchr1(const char *s, int c)
{
	int		i;
	char	find;

	find = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == find)
			return (i);
		i++;
	}
	if (s[i] == find)
		return (i);
	return (0);
}

int	ft_strspace(char *str)
{
	int	i;

	i = 0;
	if (ft_strncmp(&str[i], "", 1) == 0)
		return (1);
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		else
			return (0);
	}
	return (i);
}
