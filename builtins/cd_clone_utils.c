/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_clone_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:34:15 by selhilal          #+#    #+#             */
/*   Updated: 2023/08/08 19:33:53 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

int	fail_cd(t_env *env, char *oldpwd)
{
	char	*cd;

	if (!find_and_replace(&env, "OLDPWD=", oldpwd))
		ft_lstadd_back_env(&env,
			ft_lstnew_env(ft_strdup("OLDPWD="), oldpwd, 1));
	cd = getcwd(NULL, 0);
	if (!find_and_replace(&env, "PWD=", cd))
		ft_lstadd_back_env(&env,
			ft_lstnew_env(ft_strdup("PWD="), cd, 1));
	free(oldpwd);
	free(cd);
	return (0);
}
