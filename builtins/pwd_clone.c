/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_clone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 13:01:36 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/16 19:03:46 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

char	*pwd_env(t_env *new_env, int ret)
{
	t_env	*tmp;

	tmp = new_env;
	while (tmp)
	{
		if (!ft_strncmp(tmp->key, "PWD=", ft_strlen1(tmp->key)))
		{
			if (ret == 1)
			{
				printf("%s\n", tmp->value);
				return (tmp->value);
			}
			else
				return (tmp->value);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

int	pwd_clone(char **cmd, t_env *new_env)
{
	char	*ret;

	if (cmd[1])
	{
		ft_putstr_fd("pwd with no options\n", 2);
		return (1);
	}
	ret = getcwd(NULL, 0);
	if (ret != NULL)
	{
		printf("%s\n", ret);
		free(ret);
		return (0);
	}
	else
	{
		printf("%s\n", new_env->saved_pwd);
		return (0);
	}
	free(ret);
	return (1);
}
