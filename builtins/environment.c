/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleeps <sleeps@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 18:48:53 by mghalmi           #+#    #+#             */
/*   Updated: 2023/07/17 18:26:00 by sleeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

int	first_equale(char *string)
{
	int i;

	i = 0;
	while (string[i])
		if (string[i++] == '=')
			return i;
	return -1;
}

t_env	*empty_env(char	**envp)
{
	t_env	*env;
	
	env = NULL;
	ft_lstadd_back_env(&env, ft_lstnew_env(ft_strdup("PWD="), ft_strdup(getcwd(NULL, 0)), 1));
	ft_lstadd_back_env(&env, ft_lstnew_env(ft_strdup("SHLVL="), ft_strdup("1"), 1));
	ft_lstadd_back_env(&env, ft_lstnew_env(ft_strdup("_="), ft_strdup("/user/bin/env"), 1));
	ft_lstadd_back_env(&env, ft_lstnew_env(ft_strdup("PATH="), ft_strdup("/usr/gnu/bin:/usr/local/bin:/bin:/usr/bin:."), 0));
	return (env);
}

t_env		*envirment(char **old_env)
{
	int 	i;
	char	*key;
	char	*value;
	t_env	*new_env;

	new_env = NULL;
	i = 0;
	while (old_env[i])
	{
		key = ft_substr(old_env[i], 0, first_equale(old_env[i]));
		value = ft_substr(old_env[i], first_equale(old_env[i]), ft_strlen1(old_env[i]));
		ft_lstadd_back_env(&new_env, ft_lstnew_env(key, value, 1));
		i++;
	}
	if (i == 0)
		new_env = empty_env(old_env);
	return (new_env);
}

char	**env_exec(t_env *new_env)
{
	char	**envp;
	int i;
	t_env	*tmp;
	
	i = 0;
	tmp = new_env;
	envp = malloc(ft_lstsize_env(new_env) * sizeof(char *));
	while (tmp)
	{
		envp[i] = ft_strjoin1(envp[i], tmp->key);
		envp[i] = ft_strjoin1(envp[i], tmp->value);
		tmp = tmp->next;
		i++;
	}
	return (envp);
}

void	show_env(t_env *new_env, char **cmd)
{
	t_env	*tmp;

	tmp = new_env;
	if (cmd[1])
	{
		printf("env with no options");
        return ;
	}
	while (tmp)
	{
		if (ft_strncmp(tmp->value, "-1", 3) && tmp->option == 1)
		{
			printf("%s", tmp->key);
			if (ft_strncmp(tmp->value, "-2", 3))
				printf("%s",tmp->value);
			printf("\n");
		}
		tmp = tmp->next;
	}
}
