/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inoutfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 01:30:13 by selhilal          #+#    #+#             */
/*   Updated: 2023/08/17 00:45:16 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <sys/stat.h>

int	error_fd_in(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		perror(filename);
	return (fd);
}

int	error_fd_out(char *filename)
{
	int	fd;

	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd < 0)
		perror(filename);
	return (fd);
}

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
			perror(filename);
			return (-1);
		}
		fd = error_fd_in(filename);
		fstat(fd, NULL);
		return (open(filename, O_RDONLY));
	}
	else
	{
		fd = error_fd_out(filename);
		return (fd);
	}
}
