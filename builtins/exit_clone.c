/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_clone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:33:05 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/17 00:22:05 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

void	put_msg(char *str, char *msg)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
}

unsigned long long	checking_status(long	long status)
{
	if (status > 255)
		while (status > 255)
			status -= 256;
	if (status < 0)
		while (status < 0)
			status += 256;
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
			{
				free(tmp->value);
				tmp->value = ft_itoa_shlvl(checking_status(status));
			}
			else
			{
				free(tmp->value);
				tmp->value = ft_itoa_shlvl(status);
			}
			tmp->option = 3;
			break ;
		}
		tmp = tmp->next;
	}
}

int	find_char(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!str)
		return (1);
	if (str[i] == '+' || str[i] == '-')
		i++;
	j = i;
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
			j++;
		i++;
	}
	if (j == i)
		return (0);
	return (1);
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
		if (find_char(cmd[1]) || (ft_atoi_shlvl(cmd[1]) > 9223372036854775806
				|| ft_atoi_shlvl(cmd[1]) < -9223372036854775807))
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
