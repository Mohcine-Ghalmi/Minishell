/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_constructor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 23:43:30 by selhilal          #+#    #+#             */
/*   Updated: 2023/07/22 14:37:07 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node	*create_node(t_lsttoken *token)
{
	char	*cmd;
	int		in;
	int		out;
	t_node *node;

	node = NULL;
	while (token)
	{
		cmd = NULL;
		in = 0;
		out = 1;
		while (token->type != 4 && token)
		{
			if (token->type == 1)
			{
				cmd = token->str;
				if (token->next)
					token = token->next;
				else
					break ;
			}
			if (token->type == 2)
			{
				in = openfile(token->next->str, 0);
				if (token->next && token->next->next)
					token = token->next->next;
			}
			if (token->type == 3)
			{
				out = openfile(token->next->str, 1);
				if (token->next->next && token->next->next)
					token = token->next->next;
			}
			if (token)
				token = token->next;
		}
		addnode_back(&node, new_node(cmd, in, out));
		if (token)
			token = token->next;
	}
	return (node);
}
