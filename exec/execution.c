/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 01:10:42 by selhilal          #+#    #+#             */
/*   Updated: 2023/08/04 01:11:20 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"
#include "exec.h"

void	execution(t_node *new, t_env *envp)
{
	int				status;
	unsigned int	ifcond;
	int				in;
	int				out;

	ifcond = 2;
	status = 0;
	in = dup(0);
	out = dup(1);
	if (ft_lstsize_node(new) == 1)
		ifcond = first_built(new, envp);
	if (ifcond == 2)
	{
		dup2(new->fdin, STDIN_FILENO);
		while (new)
		{
			piper(new, envp);
			new = new->next;
		}
	}
	dup2(in, STDIN_FILENO);
	dup2(out, STDOUT_FILENO);
	update_and_wait(ifcond, status, envp);
}
