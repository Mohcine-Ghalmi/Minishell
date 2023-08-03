/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_clone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:17:50 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/03 01:15:49 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

int	find_and_replace(t_env **env, char *key, char *value)
{
	t_env	*tmp;

	tmp = *env;
	while (tmp)
	{
		if (!ft_strncmp(tmp->key, key, ft_strlen1(key)))
		{
			tmp->key = ft_strjoin1(key, "=");
			tmp->option = 1;
			tmp->value = value;
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int	find_value(t_env *env, char *key)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (!ft_strncmp(tmp->key, key, ft_strlen1(key)))
			if (!ft_strncmp(tmp->value, "", 1))
				return (1);
		tmp = tmp->next;
	}
	return (0);
}

char	*return_value(t_env *env, char *key)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (!ft_strncmp(tmp->key, key, ft_strlen1(key)))
			return (ft_strdup(tmp->value));
		tmp = tmp->next;
	}
	return (NULL);
}

int	cd_old(char *cmd, t_env **env)
{
	if (!find_value(*env, "OLDPWD"))
	{
		chdir(return_value(*env, "OLDPWD"));
		find_and_replace(env, "OLDPWD", pwd_env(*env, 0));
		find_and_replace(env, "PWD", getcwd(NULL, 0));
		pwd_env(*env, 1);
		return (0);
	}
	ft_putstr_fd("minishell: cd: OLDPWD not set\n", 2);
	return (1);
}

int	cd_clone(char **cmd, t_env *env)
{
	char	*oldpwd;

	if (!ft_strncmp(cmd[1], "-", 2))
		return (cd_old(cmd[1], &env));
	oldpwd = pwd_env(env, 0);
	if (cmd[1] == NULL)
	{
		puts("here");
		if (!find_key("HOME", env))
			return (ft_putstr_fd("minishell: cd: HOME not set", 2), 1);
		if (!find_and_replace(&env, "OLDPWD", oldpwd))
			ft_lstadd_back_env(&env,
				ft_lstnew_env(ft_strdup("OLDPWD="), oldpwd, 1));
		find_and_replace(&env, "PWD", return_value(env, "HOME"));
		chdir(return_value(env, "HOME"));
		return (0);
	}
	if (!chdir(cmd[1]))
	{
		if (!find_and_replace(&env, "OLDPWD", oldpwd))
			ft_lstadd_back_env(&env,
				ft_lstnew_env(ft_strdup("OLDPWD="), oldpwd, 1));
		find_and_replace(&env, "PWD", getcwd(NULL, 0));
		return (0);
	}
	ft_putstr_fd("minishell: cd: ", 2);
	ft_putstr_fd(cmd[1], 2);
	ft_putstr_fd(": No such file or directory\n", 2);
	return (1);
}
