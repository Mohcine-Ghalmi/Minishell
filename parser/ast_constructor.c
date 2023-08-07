/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_constructor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 23:43:30 by selhilal          #+#    #+#             */
/*   Updated: 2023/08/07 01:16:16 by mghalmi          ###   ########.fr       */
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

char	*create_single_cmd(t_lsttoken **token)
{
	char	*cmd;

	if ((*token)->str[0] == '\0')
		cmd = ft_strdup("");
	else
		cmd = ft_strdup((*token)->str);
	return (cmd);
}

char	**create_cmd_array(t_lsttoken **token, int *in, int *out, char **envp)
{
	int		i;
	int		j;
	char	**cmd;

	i = 0;
	j = 0;
	cmd = malloc(sizeof(char *) * (lenword(*token) + 1));
	while (*token && (*token)->type != 4)
	{
		if ((*token)->type == 1)
			cmd[i++] = create_single_cmd(token);
		else if ((*token)->type == 2 && (*token)->next && (*token)->next->str)
			*in = filein(token, *in);
		else if ((*token)->type == 3 && (*token)->next && (*token)->next->str)
			*out = fileout(&j, token, *out);
		else if ((*token)->type == 9 && (*token)->next && (*token)->next->str)
			*in = heredocfile(token, *in, envp);
		else if ((*token)->type == 7 && (*token)->next && (*token)->next->str)
			*out = appendfile(&j, token, *out);
		else
			break ;
		if (*token)
			*token = (*token)->next;
	}
	return (cmd[i] = NULL, cmd);
}

int	create_node(t_lsttoken *token, t_node **node, char **envp)
{
	char	**cmd;
	int		in;
	int		out;
	int		flag;

	flag = 0;
	cmd = NULL;
	while (token)
	{
		init_values(&in, &out);
		cmd = create_cmd_array(&token, &in, &out, envp);
		if (in == -1)
			flag = in;
		else
			flag = out;
		addnode_back(node, new_node(cmd, in, out));
		if (token)
			token = token->next;
	}
	return (flag);
}
