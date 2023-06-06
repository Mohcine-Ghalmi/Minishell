/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 22:10:20 by mghalmi           #+#    #+#             */
/*   Updated: 2023/01/26 16:11:23 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		write(fd, s++, 1);
}

void	here_doc(char **av, int infile)
{
	char	*str;
	char	*end;

	if (infile < 0)
		exit(1);
	end = ft_strjoin(av[2], "\n");
	str = get_next_line(STDIN_FILENO);
	if (!str)
		exit(1);
	while (end && strcmp(end, str) != 0)
	{
		ft_putstr_fd(str, infile);
		free(str);
		str = get_next_line(STDIN_FILENO);
	}
	free(end);
	close(infile);
	open("tmp.txt", O_RDONLY);
}

void	check_space(char **av, int argc)
{
	int	i;

	i = 3;
	while (av[i] && i < argc - 1)
	{
		if (ft_strspace(av[i]) > 0 || ft_strspace(av[i++]) > 0)
		{
			write(STDERR_FILENO, "Missing Command\n", 17);
			exit(1);
		}
	}
}

void	dp(int infile, int outfile)
{
	dup2(infile, STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
}

void	wl(int argc, char **env, char **av, int outfile)
{
	int	i;

	i = 3;
	while (i < argc - 2)
		pipex(av[i++], env);
	dup2(outfile, STDOUT_FILENO);
	exec(av[i], env);
	exit(1);
}
