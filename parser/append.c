/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:55:40 by selhilal          #+#    #+#             */
/*   Updated: 2023/08/05 06:11:27 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	s_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		write(fd, s++, 1);
}

int	append(char *file)
{
	if (!ft_strncmp(file, "\0", ft_strlen(file)))
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		write(STDERR_FILENO, ": No such file or directory\n", 28);
		return (-1);
	}
	return (open(file, O_CREAT | O_APPEND | O_WRONLY, 0777));
}
