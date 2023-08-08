/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 01:10:42 by selhilal          #+#    #+#             */
/*   Updated: 2023/08/08 05:38:23 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"
#include "exec.h"

void	update_and_wait(int ifcond, int status, t_env *envp)
{
	while (wait(&status) != -1)
		;
	if (WTERMSIG(status))
	{
		if (WTERMSIG(status) == 2)
			ft_putstr_fd("\n", 1);
		else if (WTERMSIG(status) == 3)
			ft_putstr_fd("Quit: 3\n", 1);
		update_status(128 + WTERMSIG(status), envp, 1);
	}
	else if (ifcond < 2)
		update_status(ifcond, envp, 1);
	else
		update_status(WEXITSTATUS(status), envp, 1);
}
