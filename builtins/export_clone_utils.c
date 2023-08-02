/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_clone_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:21:31 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/02 10:34:16 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

int	option_replace(char *key, t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (!ft_strncmp(tmp->key, key, ft_strlen1(key)))
		{
			if (key[ft_strlen1(key) - 1] == '=')
			{
				free(tmp->value);
				tmp->value = ft_strdup("");
				tmp->option = 1;
			}
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

char	*add_to_value(t_env *env, char *key, char *value)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (!ft_strncmp(key, tmp->key, ft_strlen1(key)))
			return (ft_strjoin1(tmp->value, value));
		tmp = tmp->next;
	}
	return (value);
}
