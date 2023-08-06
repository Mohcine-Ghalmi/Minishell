/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 01:10:42 by selhilal          #+#    #+#             */
/*   Updated: 2023/08/06 22:23:32 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"
#include "exec.h"

void	duper(int in, int out)
{
	dup2(in, STDIN_FILENO);
	dup2(out, STDOUT_FILENO);
}

void	execution(t_node *new, t_env *envp)
{
	int				status;
	unsigned int	ifcond;
	int				in;
	int				out;
	t_node			*node;

	ifcond = 2;
	status = 0;
	in = dup(0);
	out = dup(1);
	node = new;
	if (ft_lstsize_node(node) == 1)
		ifcond = first_built(node, envp);
	if (ifcond == 2)
	{
		dup2(node->fdin, STDIN_FILENO);
		while (node)
		{
			piper(node, envp);
			node = node->next;
		}
	}
	duper(in, out);
	update_and_wait(ifcond, status, envp);
	ft_lstclear_struct(&new);
}
