/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 14:15:43 by mghalmi           #+#    #+#             */
/*   Updated: 2023/07/13 23:07:38 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"
#include "exec.h"

void	shoose_builtins(char	*builtins, char *cmd, t_env *env)
{
	if (ft_strnstr(cmd, "echo", ft_strlen1(cmd)))
		printf("%s\n", cmd);
	else if (ft_strnstr(cmd, "cd", ft_strlen1(cmd)))
		printf("%s\n", cmd);
	else if (ft_strnstr(cmd, "pwd", ft_strlen1(cmd)))
		printf("%s\n", cmd);
	else if (ft_strnstr(cmd, "export", ft_strlen1(cmd)))
		printf("%s\n", cmd);
	else if (ft_strnstr(cmd, "unset", ft_strlen1(cmd)))
		printf("%s\n", cmd);
	else if (ft_strnstr(cmd, "env", ft_strlen1(cmd)))
		show_env(env);
	else if (ft_strnstr(cmd, "exit", ft_strlen1(cmd)))
		printf("%s\n", cmd);
}

int	check_options(char	*cmd)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	if (ft_strnstr(cmd, "cd", ft_strlen1(cmd)))
		return 1;
	while (cmd[i])
	{
		while (cmd[i] && cmd[i] == ' ')
			i++;
		if (cmd[i] != ' ' && cmd[i])
			word++;
		while (cmd[i] != ' ' && cmd[i])
			i++;
	}
	return (word);
}

void    check_builtins(char *cmd, t_env *env)
{
	int i;
	char	*builtins[7] = {
		"echo",
		"cd",
		"pwd",
		"export",
		"unset",
		"env",
		"exit"
	};

	i  = 0;
	while (i < 7)
	{
		if (ft_strnstr(cmd, builtins[i], ft_strlen1(cmd)))
		{
			if (check_options(cmd) == 1)
				shoose_builtins(builtins[i], cmd, env);
			else
				printf("error");
			exit(0);
		}
		i++;
	}
}
