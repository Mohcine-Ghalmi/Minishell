/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_clone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 22:34:08 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/20 12:27:59 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

int	size_double(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
		i++;
	return (i);
}

int	show_export(char **cmd, t_env *env)
{
	t_env	*tmp;
	int		i;

	i = 0;
	tmp = env;
	if (size_double(cmd) == 1)
	{
		while (tmp)
		{
			if (ft_strncmp("?=", tmp->key, 2))
			{
				if (tmp->option == 2)
					printf("declare -x %s\n", tmp->key);
				else if (tmp->option <= 1)
					printf("declare -x %s\"%s\"\n",
						tmp->key, tmp->value);
			}
			tmp = tmp->next;
			i++;
		}
	}
	return (i);
}

int	export_clone(char **cmd, t_env *env)
{
	int		i;
	int		ret;
	int		ret1;

	i = 1;
	ret = 0;
	ret1 = 0;
	if (!show_export(cmd, env) && cmd)
	{
		while (cmd[i])
		{
			export_helper(cmd[i], env, &ret);
			i++;
			if (ret != 0)
				ret1 = 1;
		}
	}
	return (ret1);
}

int	export_fail(char *cmd)
{
	ft_putstr_fd("minishell: export: `", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd("` not valid identifier\n", 2);
	return (1);
}

int	find_key1(char *key, t_env *env)
{
	t_env	*tmp;
	char	*key1;
	char	*key2;

	tmp = env;
	key1 = ft_substr(key, 0, ft_strlen1(key) - 1);
	key2 = ft_strjoin1(key, "=");
	while (tmp)
	{
		if (!ft_strncmp(tmp->key, key, ft_strlen1(tmp->key)))
		{
			free(key1);
			free(key2);
			return (1);
		}
		if (!ft_strncmp(tmp->key, key1, ft_strlen(tmp->key))
			|| !ft_strncmp(tmp->key, key2, ft_strlen(tmp->key)))
		{
			free(key1);
			free(key2);
			return (1);
		}
		tmp = tmp->next;
	}
	free(key1);
	free(key2);
	return (0);
}
