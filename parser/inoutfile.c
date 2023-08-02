/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inoutfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 01:30:13 by selhilal          #+#    #+#             */
/*   Updated: 2023/08/02 22:48:21 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	openfile(char *filename, int mode)
{
	if (!ft_strncmp(filename, "", ft_strlen(filename)))
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		write(STDERR_FILENO, filename, ft_strchr1(filename, 0));
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
		return (open(filename, O_RDONLY));
	}
	else
		return (open(filename, O_CREAT | O_RDWR | O_TRUNC, 0644));
}
