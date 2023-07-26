/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_constructor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 23:43:30 by selhilal          #+#    #+#             */
/*   Updated: 2023/07/26 10:48:46 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	lenword(t_lsttoken *token)
{
	int	i;

	i = 0;
	while (token)
	{
		while (token->type != 4 && token)
		{
			if (token->type == 1)
			{
				i++;
				if (token->next)
					token = token->next;
				else
					break ;
			}
			else
				break ;
		}
		if (token)
			token = token->next;
	}
	return (i);
}

t_node	*create_node(t_lsttoken *token)
{
	char	**cmd;
	int		in;
	int		i;
	int		out;
	t_node	*node;

	node = NULL;
	while (token)
	{
		cmd = malloc(sizeof(char *) * (lenword(token)));
		i = 0;
		in = 0;
		out = 1;
		while (token && token->type != 4)
		{
			if (token->type == 1)
				cmd[i++] = ft_strdup(token->str);
			else if (token->type == 2)
			{
				in = openfile(token->next->str, 0);
				if (token->next)
					token = token->next;
			}
			else if (token->type == 3)
			{
				out = openfile(token->next->str, 1);
				if (token->next)
					token = token->next;
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
