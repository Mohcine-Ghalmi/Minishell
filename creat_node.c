/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 22:13:57 by selhilal          #+#    #+#             */
/*   Updated: 2023/07/12 23:26:57 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

t_node	*struct_forM(t_token *token, t_node *node)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	new->cmd = NULL;
	new->append = NULL;
	new->heredoc = NULL;
	new->infile = NULL;
	new->outfile = NULL;
	new->next = NULL;
	while (token && token->type != PIPE)
	{
		if (token->type == WORD)
		{
			new->cmd = token->str;
			token = token->next;
		}
		else if (token->type == IN)
		{
				new->infile = token->next->str;
				token = token->next->next;
		}
		else if (token->type == OUT)
		{
				new->outfile = token->next->str;
				token = token->next->next;
		}
		else if (token->type == APPEND)
		{
				new->append = token->next->str;
				token = token->next->next;
		}
		else if (token->type == HEC)
		{
				new->heredoc = token->next->str;
				token = token->next->next;
		}
		else if (token)
			token = token->next;
	}
	ft_lstadd_front(&node, ft_lstnew2(new));
	free(new);
	return (node);
}
