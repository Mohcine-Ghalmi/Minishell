/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envirment_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:56:27 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/02 10:25:45 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

char	*shlvl(char *value)
{
	if (ft_atoi_shlvl(value) < 0)
		return (ft_itoa_shlvl(0));
	if (ft_atoi_shlvl(value) == 999)
		return (ft_strdup(""));
	return (ft_itoa_shlvl(ft_atoi_shlvl(value) + 1));
}

int	olpwd_env(t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (!ft_strncmp("OLDPWD=", tmp->key, 7))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
