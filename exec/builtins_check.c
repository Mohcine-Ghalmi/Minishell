/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 14:15:43 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/01 19:04:21 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"
#include "exec.h"

int	shoose_builtins(char **cmd, t_env *env)
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
		return (echo_clone(cmd));
	return (2);
}

void    free_double(char    **str)
{
    int i;

    i  = 0;
    while (str[i])
        free(str[i++]);
    free(str);
}

int    check_builtins(char **cmd, t_env *env)
{
	int 	i;
	char	*builtins[7] = {
		"cd",
		"export",
		"unset",
		"exit",
		"env",
		"echo",
		"pwd",
	};
	i  = 0;
	while (i < 7)
	{
		if (!ft_strncmp(cmd[0], builtins[i], ft_strlen1(cmd[0])))
			return (shoose_builtins(cmd, env));
		i++;
	}
	return (2);
}

int first_built(t_node*new, t_env *env)
{
    int     ret;

    ret  = 0;
	if (new->fdout > 2)
		dup2(new->fdout, STDOUT_FILENO);
	ret = check_builtins(new->cmd, env);
    return (ret);
}
