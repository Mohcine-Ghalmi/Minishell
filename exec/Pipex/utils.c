/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:26:48 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/11 16:03:32 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*path_join(char *path, char *bin)
{
	char	*joined;
	int		i;
	int		j;
	int		len;

	if (!bin)
		return (NULL);
	len = ft_strlen(path) + ft_strlen(bin);
	joined = malloc(sizeof(char) * (len + 2));
	if (!joined)
		return (NULL);
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

char	*ft_strdup1(char *str, unsigned int n)
{
	char				*duped;
	unsigned int		i;

	i = 0;
	duped = malloc(sizeof(char) * (n + 1));
	if (!duped)
		return (NULL);
	while (i < n)
		duped[i++] = *str++;
	duped[n] = 0;
	return (duped);
}

int	ft_strchr1(const char *s, int c)
{
	int		i;
	char	find;

	if (!s)
		return (0);
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
