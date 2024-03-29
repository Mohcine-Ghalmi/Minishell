/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 14:15:43 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/20 11:57:13 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"
#include "exec.h"

int	shoose_builtins(char **cmd, t_env *env, int fd)
{
	if (!ft_strncmp(cmd[0], "cd", ft_strlen1(cmd[0])))
		return (cd_clone(cmd, env));
	else if (!ft_strncmp(cmd[0], "export", ft_strlen1(cmd[0])))
		return (export_clone(cmd, env));
	else if (!ft_strncmp(cmd[0], "unset", ft_strlen1(cmd[0])))
		return (unset_clone(env, cmd));
	else if (!ft_strncmp(cmd[0], "exit", ft_strlen1(cmd[0])))
		return (exit_clone(env, cmd));
	else if (!ft_strncmp(cmd[0], "pwd", ft_strlen1(cmd[0])))
		return (pwd_clone(cmd, env));
	else if (!ft_strncmp(cmd[0], "env", ft_strlen1(cmd[0])))
		return (show_env(env, cmd));
	else if (!ft_strncmp(cmd[0], "echo", ft_strlen1(cmd[0])))
		return (echo_clone(cmd, env, fd));
	return (2);
}

void	free_double(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
		free(str[i++]);
	free(str);
}

int	check_builtins(char **cmd, t_env *env, int fd)
{
	int		i;
	char	*builtins[7];

	builtins[0] = "cd";
	builtins[1] = "export";
	builtins[2] = "unset";
	builtins[3] = "exit";
	builtins[4] = "env";
	builtins[5] = "echo";
	builtins[6] = "pwd";
	i = 0;
	while (i < 7)
	{
		if (cmd[0] != NULL && cmd[0][0] != '\0')
			if (!ft_strncmp(cmd[0], builtins[i], ft_strlen1(builtins[i])))
				return (shoose_builtins(cmd, env, fd));
		i++;
	}
	return (2);
}

int	first_built(t_node *new, t_env *env)
{
	int	ret;
	int	fd;

	fd = 1;
	if (new->fdout > 2)
	{
		fd = new->fdout;
		dup2(fd, STDOUT_FILENO);
	}
	ret = check_builtins(new->cmd, env, fd);
	return (ret);
}
