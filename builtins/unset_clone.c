/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_clone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:45:48 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/08 04:47:49 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

int	checking_args(char *cmd)
{
	int	i;

	i = 0;
	if (cmd[i] < 48 & cmd[i] > 57)
		i++;
	while (cmd[i])
	{
		if ((cmd[i] >= 33 && cmd[i] <= 42) || (cmd[i] > 43 && cmd[i] <= 47)
			|| (cmd[i] > 58 && cmd[i] <= 64)
			|| (cmd[i] >= 91 && cmd[i] <= 94 || cmd[i] == 96) 
			|| cmd[i] >= 123)
			return (i + 1);
		i++;
	}
	return (0);
}

int	find_key(char *key, t_env *env)
{
	t_env	*tmp;
	char	*key1;

	tmp = env;
	key1 = ft_substr(key, 0, ft_strlen1(key) - 1);
	while (tmp)
	{
		if (!ft_strncmp(tmp->key, key, ft_strlen1(tmp->key)))
		{
			free(key1);
			return (1);
		}
		if (!ft_strncmp(tmp->key, key1,
				ft_strlen(tmp->key)))
		{
			free(key1);
			return (1);
		}
		tmp = tmp->next;
	}
	free(key1);
	return (0);
}

void	delete_key(char *key, t_env **env)
{
	t_env	*tmp;
	t_env	*prev;

	prev = NULL;
	tmp = *env;
	while (tmp && ft_strncmp(tmp->key, key, ft_strlen1(tmp->key) - 1))
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp)
	{
		if (!prev)
			*env = tmp->next;
		else 
			prev->next = tmp->next;
		free(tmp->key);
		free(tmp->value);
		free(tmp);
	}
}

int	unset_clone(t_env *env, char **cmd)
{
	int	i;
	int	ret;
	int	ret1;

	i = 1; 
	ret = 0;
	ret1 = 0;
	while (cmd[i])
	{
		if (checking_args(cmd[i]) || !cmd[i][0])
		{
			ft_putstr_fd("minishell: unset: `", 2);
			ft_putstr_fd(cmd[i], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			ret = 1;
		}
		else
			delete_key(cmd[i], &env);
		if (ret == 1)
			ret1 = ret;
		i++;
	}
	return (ret1);
}
