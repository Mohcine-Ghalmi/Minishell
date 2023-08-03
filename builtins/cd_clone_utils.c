/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_clone_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:34:15 by selhilal          #+#    #+#             */
/*   Updated: 2023/08/03 17:34:58 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

int	fail_cd(t_env *env, char *oldpwd)
{
	if (!find_and_replace(&env, "OLDPWD", oldpwd))
		ft_lstadd_back_env(&env,
			ft_lstnew_env(ft_strdup("OLDPWD="), oldpwd, 1));
	find_and_replace(&env, "PWD", getcwd(NULL, 0));
	return (0);
}
