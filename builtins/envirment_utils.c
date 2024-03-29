/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envirment_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:56:27 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/16 22:19:50 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

char	*shlvl(char *value)
{
	if (ft_atoi_shlvl(value) < 0)
		return (ft_itoa_shlvl(0));
	if (ft_atoi_shlvl(value) == 999)
		return (ft_strdup(""));
	if (ft_atoi_shlvl(value) > 999)
	{
		ft_putstr_fd("minishell: warning: shell level (", 2);
		ft_putstr_fd(value, 2);
		ft_putstr_fd(") too high, resetting to 1\n", 2);
		return (ft_strdup("1"));
	}
	return (ft_itoa_shlvl(ft_atoi_shlvl(value) + 1));
}

int	olpwd_env(t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (!ft_strncmp("OLDPWD=", tmp->key, 7))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

char	*shlvl_value(char *shlvl_key)
{
	char	*shlvl_val;
	char	*value;

	shlvl_val = ft_substr(shlvl_key, first_equale(shlvl_key), \
				ft_strlen1(shlvl_key));
	value = shlvl(shlvl_val);
	free(shlvl_val);
	return (value);
}

t_env	*main_env(char **old_env, int *i)
{
	t_env	*new_env;
	char	*key;
	char	*value;

	new_env = NULL;
	ft_lstadd_back_env(&new_env,
		ft_lstnew_env(ft_strdup("?="), ft_strdup("0"), 3));
	while (old_env[*i])
	{
		key = NULL;
		value = NULL;
		key = ft_substr(old_env[*i], 0, first_equale(old_env[*i]));
		if (!ft_strncmp(key, "SHLVL=", 7))
			value = shlvl_value(old_env[*i]);
		else
			value = ft_substr(old_env[*i],
					first_equale(old_env[*i]), ft_strlen1(old_env[*i]));
		ft_lstadd_back_env(&new_env, ft_lstnew_env(key, value, 1));
		(*i)++;
	}
	new_env->saved_pwd = NULL;
	return (new_env);
}
