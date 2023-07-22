/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 14:15:43 by mghalmi           #+#    #+#             */
/*   Updated: 2023/07/22 13:10:32 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"
#include "exec.h"

void	shoose_builtins(char **cmd, t_env *env)
{
	if (!ft_strncmp(cmd[0], "cd", ft_strlen1(cmd[0])))
		cd_clone(cmd, env);
	else if (!ft_strncmp(cmd[0], "export", ft_strlen1(cmd[0])))
		export_clone(cmd, env);
	else if (!ft_strncmp(cmd[0], "unset", ft_strlen1(cmd[0])))
		unset_clone(env, cmd);
	else if (!ft_strncmp(cmd[0], "exit", ft_strlen1(cmd[0])))
		printf("builtins %s\n", cmd[0]);
	else if (!ft_strncmp(cmd[0], "pwd", ft_strlen1(cmd[0])))
		pwd_clone(cmd, env);
	else if (!ft_strncmp(cmd[0], "env", ft_strlen1(cmd[0])))
		show_env(env, cmd);
	else if (!ft_strncmp(cmd[0], "echo", ft_strlen1(cmd[0])))
		echo_clone(cmd);
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
		{
			shoose_builtins(cmd, env);
			return (1);
		}
		i++;
	}
	return (0);
}
