/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_clone_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:21:31 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/08 04:52:08 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

void	add_to_env(char *cmd, t_env *env)
{
	char	*prb;
	char	*key;
	char	*value;

	key = ft_substr(cmd, 0, first_equale(cmd));
	value = ft_substr(cmd, first_equale(cmd), ft_strlen1(cmd));
	if (key[first_equale(cmd) - 2] == '+')
	{
		key = ft_substr(cmd, 0, first_equale(cmd) - 2);
		key = ft_strjoin1(key, "=");
		value = add_to_value(env, key, value);
	}
	if (find_key(key, env))
	{
		prb = ft_strjoin1("unset ", ft_substr(cmd, 0, first_equale(key) - 1));
		unset_clone(env, ft_split(prb, ' '));
		free(prb);
	}
	ft_lstadd_back_env(&env, ft_lstnew_env(key, value, 1));
}

int	option_replace(char *key, t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (!ft_strncmp(tmp->key, key, ft_strlen1(key)))
		{
			if (key[ft_strlen1(key) - 1] == '=')
			{
				free(tmp->value);
				tmp->value = ft_strdup("");
				tmp->option = 1;
			}
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

char	*add_to_value(t_env *env, char *key, char *value)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (!ft_strncmp(key, tmp->key, ft_strlen1(key)))
			return (ft_strjoin1(tmp->value, value));
		tmp = tmp->next;
	}
	return (value);
}

int	checking_dash(char *cmd)
{
	int	i;
	int	len;

	i = 0;
	len = first_equale(cmd) - 1;
	if (cmd[first_equale(cmd) - 2] == '+')
		len -= 1;
	if (len <= 0)
		len = ft_strlen1(cmd);
	while (i < len)
	{
		if ((cmd[i] >= 33 && cmd[i] <= 42) || (cmd[i] > 43 && cmd[i] <= 64)
			|| (cmd[i] >= 91 && cmd[i] <= 96) 
			|| cmd[i] >= 123 || (i < len - 1 && cmd[i] == '+'
				&& cmd[i + 1] != '='))
		{
			ft_putstr_fd("minishell: export: `", 2);
			ft_putstr_fd(cmd, 2);
			ft_putstr_fd("` not valid identifier\n", 2);
			return (i + 1);
		}
		i++;
	}
	return (0);
}

void	export_helper(char *cmd, t_env *env, int *ret)
{
	if (cmd[0] == '\0')
	{
		*ret = export_fail(cmd);
		return ;
	}
	if (!option_replace(cmd, env))
	{
		if (ft_strchr1(cmd, '='))
		{
			if (!checking_dash(cmd))
				add_to_env(cmd, env);
			else
				*ret = 1;
		}
		else
		{
			if (!checking_dash(cmd))
				ft_lstadd_back_env(&env,
					ft_lstnew_env(ft_strdup(cmd), ft_strdup(""), 2));
			else
				*ret = 1;
		}
	}
}
