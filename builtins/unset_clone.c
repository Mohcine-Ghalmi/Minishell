/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_clone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:45:48 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/02 10:43:37 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

int	find_key(char *key, t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (!ft_strncmp(tmp->key, key, ft_strlen1(key)))
			return (1);
		if (!ft_strncmp(tmp->key, ft_substr(key, 0, ft_strlen1(key) - 1),
				ft_strlen(key)))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	delete_key(char *key, t_env *env)
{
	t_env	*tmp;
	t_env	*prev;

	prev = NULL;
	tmp = env;
	while (tmp && ft_strncmp(tmp->key, key, ft_strlen1(key)))
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp)
		if (prev)
			prev->next = tmp->next;
	free(tmp->key);
	free(tmp->value);
	free(tmp);
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
		if (!find_key(cmd[i], env))
		{
			ft_putstr_fd("minishell: unset: `", 2);
			ft_putstr_fd(cmd[i], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			ret = 1;
		}
		else
			delete_key(cmd[i], env);
		if (ret == 1)
			ret1 = ret;
		i++;
	}
	return (ret1);
}
