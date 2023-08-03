/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_constructor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 23:43:30 by selhilal          #+#    #+#             */
/*   Updated: 2023/08/03 16:28:29 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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

void	free_cmds(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
		free(cmd[i++]);
	free(cmd);
}

t_node	*create_node(t_lsttoken *token)
{
	char	**cmd;
	int		in;
	int		i;
	int		out;
	int		flagout;
	int		flagin;
	t_node	*node;

	node = NULL;
	flagout = 0;
	flagin = 0;
	while (token)
	{
		i = 0;
		in = 0;
		out = 1;
		cmd = malloc(sizeof(char *) * (lenword(token) + 1));
		while (token && token->type != 4)
		{
			if (token->type == 1)
				cmd[i++] = ft_strdup(token->str);
			else if (token->type == 2 && token->next && token->next->str)
			{
				if (flagin != -1)
				{
					in = openfile(token->next->str, STDIN_FILENO);
					flagin = in;
				}
				if (token->next)
					token = token->next;
			}
			else if (token->type == 3 && token->next && token->next->str)
			{
				if (flagout != -1)
				{
					out = openfile(token->next->str, STDOUT_FILENO);
					flagout = out;
				}
				if (token->next)
					token = token->next;
			}
			else if (token->type == 9 && token->next && token->next->str)
			{
				in = heredoc(token->next->str);
				if (token->next)
					token = token->next;
			}
			else if (token->type == 7 && token->next && token->next->str)
			{
				out = append(token->next->str);
				if (token->next)
					token = token->next;
			}
			if (token)
				token = token->next;
		}
		cmd[i] = NULL;
		addnode_back(&node, new_node(cmd, in, out));
		if (token)
			token = token->next;
	}
	return (node);
}
