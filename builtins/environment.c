/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleeps <sleeps@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 18:48:53 by mghalmi           #+#    #+#             */
/*   Updated: 2023/07/16 18:45:25 by sleeps           ###   ########.fr       */
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
		ft_lstadd_back_env(&new_env, ft_lstnew_env(key, value));
		i++;
	}
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

void	show_env(t_env *new_env)
{
	t_env	*tmp;

	tmp = new_env;
	while (tmp)
	{
		printf("%s%s\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
}
