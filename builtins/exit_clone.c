/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_clone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:33:05 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/06 22:01:07 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

unsigned int	checking_status(unsigned int status)
{
	if (status > 255)
		while (status > 255)
			status -= 256;
	return (status);
}

void	update_status(unsigned int status, t_env *env, int i)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (!ft_strncmp("?=", tmp->key, 2))
		{
			if (i == 1)
				tmp->value = ft_itoa_shlvl(checking_status(status));
			else
				tmp->value = ft_itoa_shlvl(status);
			tmp->option = 3;
			break ;
		}
		tmp = tmp->next;
	}
}

int	find_char(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (1);
		i++;
	}
	return (0);
}

void	put_msg(char *str, char *msg)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
}

int	exit_clone(t_env *env, char **cmd)
{
	int	ret;

	ret = 0;
	if (cmd[2] && !find_char(cmd[1]))
	{
		put_msg("", "exit: too many arguments");
		return (update_status(1, env, 1), 1);
	}
	if (cmd[1])
	{
		if (find_char(cmd[1]))
		{
			update_status(255, env, 1);
			printf("exit\n");
			put_msg(cmd[1], "exit: numeric argument required");
			exit(255);
		}
		printf("exit\n");
		exit(ft_atoi_shlvl(cmd[1]));
	}
	ret = ft_atoi_shlvl(return_value(env, "?="));
	return (update_status(ret, env, 1), exit(ret), 0);
}
