/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:24:34 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/05 20:40:38 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	openfile_cmd(char *filename, int mode)
{
	if (mode == STDIN_FILENO)
	{
		if (access(filename, F_OK))
			return (0);
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
		return (NULL);
	path = env[i] + 5;
	if (!ft_strchr1(path, ':'))
		return (path_join(path, cmd));
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
	return (NULL);
}

void	exec(char **cmd, char **env)
{
	char	**args;
	char	*path;

	args = cmd;
	if (!*env || cmd[0][0] == '\0')
		path = NULL;
	else
		path = getpath(args[0], env);
	if (!path && (ft_strchr1(cmd[0], '/') || cmd[0][0] == '/'))
		path = args[0];
	if (path == NULL || access(path, X_OK) == -1)
	{
		write(STDERR_FILENO, "minishell: ", 12);
		write(STDERR_FILENO, cmd[0], ft_strchr1(cmd[0], 0));
		write(STDERR_FILENO, ": command not found\n", 20);
		exit(127);
	}
	if (execve(path, args, env) < 0)
		exit(errno + 128);
}

void	exec1(char *cmd, char **env)
{
	char	**args;
	char	*path;

	args = ft_split(cmd, ' ');
	path = getpath(args[0], env);
	execve(path, args, env);
}
