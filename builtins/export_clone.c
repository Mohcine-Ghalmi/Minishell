/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_clone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 22:34:08 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/03 21:19:31 by mghalmi          ###   ########.fr       */
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
				printf("\033[32;1mdeclare -x\033[0m %s\n", tmp->key);
			else if (tmp->option <= 1)
				printf("\033[32;1mdeclare -x\033[0m %s\"%s\"\n",
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
	char	*key;
	char	*value;
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
