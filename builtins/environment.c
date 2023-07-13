/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 18:48:53 by mghalmi           #+#    #+#             */
/*   Updated: 2023/07/13 02:13:43 by mghalmi          ###   ########.fr       */
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

void	show_env(t_env *new_env)
{
	while (new_env)
	{
		printf("%s%s\n", new_env->key, new_env->value);
		new_env = new_env->next;
	}
}

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	show_env(envirment(envp));	
}