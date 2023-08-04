/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_constructor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 23:43:30 by selhilal          #+#    #+#             */
/*   Updated: 2023/08/04 13:47:15 by selhilal         ###   ########.fr       */
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

char	**create_cmd_array(t_lsttoken **token, int *in, int *out, int *flag)
{
	int		i;
	char	**cmd;

	i = 0;
	cmd = malloc(sizeof(char *) * (lenword(*token) + 1));
	while (*token && (*token)->type != 4)
	{
		if ((*token)->type == 1)
			cmd[i++] = ft_strdup((*token)->str);
		else if ((*token)->type == 2 && (*token)->next && (*token)->next->str)
			*in = filein(flag, token, *in);
		else if ((*token)->type == 3 && (*token)->next && (*token)->next->str)
			*out = fileout(flag, token, *out);
		else if ((*token)->type == 9 && (*token)->next && (*token)->next->str)
			*in = heredocfile(token, *in);
		else if ((*token)->type == 7 && (*token)->next && (*token)->next->str)
			*out = appendfile(token, *out);
		else
			break ;
		if (*token)
			*token = (*token)->next;
	}
	cmd[i] = NULL;
	return (cmd);
}

void	create_node(t_lsttoken *token, t_node **node)
{
	char	**cmd;
	int		in;
	int		i;
	int		out;
	int		flag;

	flag = 0;
	cmd = NULL;
	while (token)
	{
		init_values(&i, &in, &out);
		cmd = create_cmd_array(&token, &in, &out, &flag);
		addnode_back(node, new_node(cmd, in, out));
		if (token)
			token = token->next;
	}
}
