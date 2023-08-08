/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inoutfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 01:30:13 by selhilal          #+#    #+#             */
/*   Updated: 2023/08/08 08:37:42 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <sys/stat.h>

int	openfile(char *filename, int mode)
{
	int	fd;

	if (filename[0] == '\0')
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		write(STDERR_FILENO, ": No such file or directory\n", 28);
		return (-1);
	}
	if (mode == STDIN_FILENO)
	{
		if (access(filename, F_OK))
		{
			ft_putstr_fd("minishell: ", STDERR_FILENO);
			write(STDERR_FILENO, filename, ft_strchr1(filename, 0));
			write(STDERR_FILENO, ": No such file or directory\n", 28);
			return (-1);
		}
		fd = open(filename, O_RDONLY);
		fstat(fd, NULL);
		return (open(filename, O_RDONLY));
	}
	else
		return (open(filename, O_CREAT | O_RDWR | O_TRUNC, 0644));
}
