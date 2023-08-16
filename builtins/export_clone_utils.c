/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_clone_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:21:31 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/17 00:22:46 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

void	add_to_env(char *cmd, t_env *env)
{
	char	*prb;
	char	*key;
	char	*value;
	char	**spliter;
	char	*old;

	key = ft_substr(cmd, 0, first_equale(cmd));
	value = ft_substr(cmd, first_equale(cmd), ft_strlen1(cmd));
	if (key[first_equale(cmd) - 2] == '+')
	{
		old = ft_substr(cmd, 0, first_equale(cmd) - 2);
		free(key);
		key = ft_strjoin1(old, "=");
		value = add_to_value(env, key, value);
		free(old);
	}
	if (find_key(key, env))
	{
		old = ft_substr(cmd, 0, first_equale(key) - 1);
		prb = ft_strjoin1("unset ", old);
		spliter = ft_split(prb, ' ');
		unset_clone(env, spliter);
		free_tree(old, prb, spliter);
	}
	ft_lstadd_back_env(&env, ft_lstnew_env(key, value, 1));
}

int	option_replace(char *key, t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (!ft_strncmp(tmp->key, key, ft_strlen1(tmp->key) - 1))
		{
			if (key[ft_strlen1(key) - 1] == '=')
			{
				free(tmp->value);
				tmp->value = ft_strdup("");
				tmp->option = 1;
				return (1);
			}
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
			return (ft_strjoin_word(tmp->value, value));
		tmp = tmp->next;
	}
	return (value);
}

int	checking_dash(char *cmd)
{
	int	i;
	int	len;

	i = -1;
	len = first_equale(cmd) - 1;
	if (cmd[first_equale(cmd) - 2] == '+')
		len -= 1;
	if (len <= 0)
		len = ft_strlen1(cmd);
	while (++i < len)
	{
		if ((cmd[0] >= 33 && cmd[0] <= 43) || (cmd[0] > 43 && cmd[0] <= 64)
			|| (cmd[0] >= 91 && cmd[0] <= 94) || cmd[0] == 96
			|| cmd[0] >= 123 || (i < len - 1 && cmd[i] == '+'
				&& cmd[i + 1] != '='))
		{
			ft_putstr_fd("minishell: export: `", 2);
			ft_putstr_fd(cmd, 2);
			ft_putstr_fd("` not valid identifier\n", 2);
			return (i + 1);
		}
		if (cmd[0] == 95 && !cmd[1])
			return (1);
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
