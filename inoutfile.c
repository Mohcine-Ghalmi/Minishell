/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inoutfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 01:30:13 by selhilal          #+#    #+#             */
/*   Updated: 2023/08/01 14:34:36 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

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

int	openfile(char *filename, int mode)
{
	if (mode == STDIN_FILENO)
	{
		if (access(filename, F_OK))
		{
			write(STDERR_FILENO, filename, ft_strchr1(filename, 0));
			write(STDERR_FILENO, ": No such file or directory\n", 28);
			return (mode);
		}
		return (open(filename, O_RDONLY));
	}
	else
		return (open(filename, O_CREAT | O_RDWR | O_TRUNC, 0644));
}
