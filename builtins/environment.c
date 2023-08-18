/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 18:48:53 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/18 14:06:51 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

int	first_equale(char *string)
{
	int	i;

	i = 0;
	while (string[i])
		if (string[i++] == '=')
			return (i);
	return (-1);
}

t_env	*empty_env(t_env *new_env)
{
	t_env	*env;
	char	*pwd;

	env = new_env;
	pwd = getcwd(NULL, 0);
	if (!find_key("?=", new_env))
		ft_lstadd_back_env(&new_env,
			ft_lstnew_env(ft_strdup("?="), ft_strdup("0"), 3));
	if (pwd)
		ft_lstadd_back_env(&env, ft_lstnew_env(ft_strdup("PWD="),
				ft_strdup(pwd), 1));
	ft_lstadd_back_env(&env, ft_lstnew_env(ft_strdup("SHLVL="),
			ft_strdup("1"), 1));
	ft_lstadd_back_env(&env, ft_lstnew_env(ft_strdup("_="),
			ft_strdup("/user/bin/env/./minishell"), 1));
	ft_lstadd_back_env(&env, ft_lstnew_env(ft_strdup("PATH="),
			ft_strdup("/usr/gnu/bin:/usr/local/bin:/bin:/usr/bin:."), 3));
	new_env->saved_pwd = NULL;
	free(pwd);
	return (env);
}

t_env	*envirment(char **old_env)
{
	int		i;
	t_env	*new_env;

	i = 0;
	new_env = main_env(old_env, &i);
	if (!olpwd_env(new_env))
	{
		if (!find_key("?=", new_env))
			ft_lstadd_back_env(&new_env,
				ft_lstnew_env(ft_strdup("?="), ft_strdup("0"), 3));
		ft_lstadd_back_env(&new_env,
			ft_lstnew_env(ft_strdup("OLDPWD="), ft_strdup(""), 2));
		i++;
	}
	if (i == 1)
		new_env = empty_env(new_env);
	return (new_env);
}

char	**env_exec(t_env *new_env)
{
	char	**envp;
	int		i;
	t_env	*tmp;

	i = 0;
	tmp = new_env;
	envp = (char **)malloc((ft_lstsize_env(new_env) + 1) * sizeof(char *));
	if (!envp)
		return (NULL);
	while (tmp)
	{
		if (!ft_strncmp(tmp->key, "?=", 3) && tmp->value)
			tmp  = tmp->next;
		if (tmp->key == NULL)
			envp[i] = ft_strdup("");
		else
			envp[i] = ft_strdup(tmp->key);
		if (!tmp->value)
			tmp->value = ft_strdup("");
		envp[i] = ft_strjoin(envp[i], tmp->value);
		tmp = tmp->next;
		i++;
	}
	envp[i] = NULL;
	return (envp);
}

int	show_env(t_env *new_env, char **cmd)
{
	t_env	*tmp;

	tmp = new_env;
	if (cmd[1])
	{
		ft_putstr_fd("env with no options\n", 1);
		return (1);
	}
	if (cmd)
	{
		while (tmp)
		{
			if (ft_strncmp("?=", tmp->key, 2))
				if (tmp->option == 1)
					printf("%s%s\n", tmp->key, tmp->value);
			tmp = tmp->next;
		}
	}
	return (0);
}
