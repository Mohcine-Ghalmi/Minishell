/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_clone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:17:50 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/16 17:19:55 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

int	find_and_replace(t_env **env, char *key, char *value)
{
	t_env	*tmp;

	tmp = *env;
	if (!key || !value)
		return (0);
	while (tmp)
	{
		if (!ft_strncmp(tmp->key, key, ft_strlen1(tmp->key)))
		{
			tmp->option = 1;
			free(tmp->value);
			tmp->value = ft_strdup(value);
			return (1);
		}
		tmp = tmp->next;
	}
	free(value);
	return (0);
}

int	find_value(t_env *env, char *key)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (!ft_strncmp(tmp->key, key, ft_strlen1(tmp->key)))
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
		if (!ft_strncmp(tmp->key, key, ft_strlen1(tmp->key)))
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

int	cd_old(t_env **env)
{
	char	*cd;
	char	**spliter;

	if (!find_value(*env, "OLDPWD=") && return_value(*env, "OLDPWD="))
	{
		chdir(return_value(*env, "OLDPWD="));
		if (!pwd_env(*env, 0))
		{
			spliter = ft_split("unset OLDPWD=", ' ');
			unset_clone(*env, spliter);
			free_double(spliter);
		}
		else
			find_and_replace(env, "OLDPWD=", pwd_env(*env, 0));
		cd = getcwd(NULL, 0);
		find_and_replace(env, "PWD=", cd);
		free(cd);
		pwd_env(*env, 1);
		return (0);
	}
	ft_putstr_fd("minishell: cd: OLDPWD not set\n", 2);
	return (1);
}

int	cd_clone(char **cmd, t_env *env)
{
	char	*oldpwd;

	if (cmd[1] != NULL)
		if (!ft_strncmp(cmd[1], "-", 2))
			return (cd_old(&env));
	oldpwd = getcwd(NULL, 0);
	if (cmd[1] == NULL)
	{
		if (!find_key("HOME=", env))
			return (ft_putstr_fd("minishell: cd: HOME not set\n", 2)
				, free(oldpwd), 1);
		if (!find_and_replace(&env, "OLDPWD=", oldpwd))
			ft_lstadd_back_env(&env,
				ft_lstnew_env(ft_strdup("OLDPWD="), oldpwd, 1));
		replace_pwd(&env);
		chdir(return_value(env, "HOME="));
		return (free(oldpwd), 0);
	}
	else if (!chdir(cmd[1]))
		return (free(oldpwd), fail_cd(env, oldpwd));
	free(oldpwd);
	ft_putstr_fd("minishell: cd: ", 2);
	perror(cmd[1]);
	return (1);
}
