/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 14:15:43 by mghalmi           #+#    #+#             */
/*   Updated: 2023/07/15 17:32:23 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"
#include "exec.h"

void	shoose_builtins(char	*builtins, char **cmd, t_env *env)
{
	if (!ft_strncmp(cmd[0], "cd", ft_strlen1(cmd[0])))
		cd_clone(cmd, env);
	else if (!ft_strncmp(cmd[0], "export", ft_strlen1(cmd[0])))
		printf("builtins %s\n", cmd[0]);
	else if (!ft_strncmp(cmd[0], "unset", ft_strlen1(cmd[0])))
		printf("builtins %s\n", cmd[0]);
	else if (!ft_strncmp(cmd[0], "exit", ft_strlen1(cmd[0])))
		printf("builtins %s\n", cmd[0]);
	else if (!ft_strncmp(cmd[0], "pwd", ft_strlen1(cmd[0])))
		pwd_clone(cmd, env);
	else if (!ft_strncmp(cmd[0], "env", ft_strlen1(cmd[0])))
		show_env(env);
	else if (!ft_strncmp(cmd[0], "echo", ft_strlen1(cmd[0])))
		printf("builtins %s\n", cmd[0]);
}

void    free_double(char    **str)
{
    int i;

    i  = 0;
    while (str[i])
        free(str[i++]);
    free(str);
}

int    check_builtins(char *cmd, t_env *env)
{
	int 	i;
	char	**builts_args;
	char	*builtins[7] = {
		"cd",
		"export",
		"unset",
		"exit",
		"env",
		"echo",
		"pwd",
	};
	builts_args = ft_split(cmd, ' ');
	i  = 0;
	while (i < 7)
	{
		if (!ft_strncmp(builts_args[0], builtins[i], ft_strlen1(cmd)))
		{
			shoose_builtins(builtins[i], builts_args, env);
			free_double(builts_args);
			return (1);
		}
		i++;
	}
	free_double(builts_args);
	return (0);
}
