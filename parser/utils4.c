/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 00:15:05 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/17 00:21:41 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft___pwd(t_env *envp)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (pwd != NULL)
	{
		free(envp->saved_pwd);
		envp->saved_pwd = pwd;
	}
}

void	for_stats(t_env *new_envp, t_node *node, int ret)
{
	if (node->fdin > 2 || node->fdout > 2)
		update_status(0, new_envp, 0);
	if (ret == -1)
		update_status(1, new_envp, 0);
}
