/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_clone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 22:34:08 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/05 23:49:33 by mghalmi          ###   ########.fr       */
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
			if (tmp->option == 2)
				printf("declare -x %s\n", tmp->key);
			else if (tmp->option <= 1)
				printf("declare -x %s\"%s\"\n",
					tmp->key, tmp->value);
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
	if (!show_export(cmd, env))
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
