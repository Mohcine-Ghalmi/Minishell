/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:24:34 by mghalmi           #+#    #+#             */
/*   Updated: 2023/06/07 18:27:00 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	openfile(char *filename, int mode)
{
	if (mode == STDIN_FILENO)
	{
		if (access(filename, F_OK))
			return (-1);
		return (open(filename, O_RDONLY));
	}
	else
		return (open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644));
}

char	*getpath(char *cmd, char **env)
{
	char	*path;
	char	*dir;
	char	*bin;
	int		i;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	if (!env[i])
		return (cmd);
	path = env[i] + 5;
	while (path && ft_strchr1(path, ':') > 0)
	{
		dir = ft_strdup1(path, ft_strchr1(path, ':'));
		bin = path_join(dir, cmd);
		free(dir);
		if (access(bin, F_OK) == 0)
			return (bin);
		free(bin);
		path += ft_strchr1(path, ':') + 1;
	}
	return (cmd);
}

void	exec(char *cmd, char **env)
{
	char	**args;
	char	*path;

	args = ft_split(cmd, ' ');
	path = getpath(args[0], env);
	if (execve(path, args, env) < 0)
	{
		write(STDERR_FILENO, cmd, ft_strchr1(cmd, 0));
		write(STDERR_FILENO, ": command not found\n", 20);
	}
}

void one_cmd(int argc, char *cmd, char **env)
{
	if (argc == 2)
			exec(cmd, env);
}

int	main(int argc, char **av, char **env)
{
	int	infile;
	int	outfile;
	int cmd2;

	if (argc >= 2)
	{
		if (ft_strspace(av[1]) > 0)
		{
			write(STDERR_FILENO, "Missing Command\n", 17);
			return (0);
		}
		one_cmd(argc, av[1], env);
		cmd2 = 2;
		infile = openfile(av[2], STDIN_FILENO);
		if (infile != -1)
		{
			cmd2 = 3;
			dup2(infile, STDIN_FILENO);
		}
		if (av[cmd2] && ft_strspace(av[cmd2]) > 0)
		{
			write(STDERR_FILENO, "Missing Command\n", 17);
			return (0);
		}
		if (!av[4])
		{
			outfile = openfile(av[4], STDOUT_FILENO);
			if (outfile != -1)
				dup2(outfile, STDOUT_FILENO);
		}
		if (argc == 3)
			exec(av[1], env);
		pipex1(av[1], av[cmd2], env);
		exit(0);
	}
	write(STDERR_FILENO, "Invalid number of arguments.\n", 29);
	return (0);
}
