/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_constructor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 23:43:30 by selhilal          #+#    #+#             */
/*   Updated: 2023/07/31 15:15:41 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

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

//char	**wl(int *in, int *out, t_lsttoken *token)
//{
//	int		i;
//	char	**cmd;
//
//	i = 0;
//	cmd = malloc(sizeof(char *) * (lenword(token) + 1));
//	while (token && token->type != 4)
//	{
//		if (token->type == 1)
//			cmd[i++] = ft_strdup(token->str);
//		else if (token->type == 2)
//		{
//			if (token->next && token->next->str)
//				*in = openfile(token->next->str, 0);
//			if (token->next)
//				token = token->next;
//		}
//		else if (token->type == 3)
//		{
//			if (token->next && token->next->str)
//				*out = openfile(token->next->str, 1);
//			if (token->next)
//				token = token->next;
//		}
//		if (token)
//			token = token->next;
//	}
//	return (cmd);
//}

//t_node	*create_node(t_lsttoken *token)
//{
//	char	**cmd;
//	int		in;
//	int		i;
//	int		out;
//	t_node	*node;
//
//	node = NULL;
//	while (token)
//	{
//		i = 0;
//		in = 0;
//		out = 1;
//		cmd = wl(&in, &out, token);
//		addnode_back(&node, new_node(cmd, in, out));
//		if (token)
//			token = token->next;
//	}
//	return (node);
//}

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
		cmd = malloc(sizeof(char *) * (lenword(token) + 1));
		i = 0;
		in = 0;
		out = 1;
		while (token && token->type != 4)
		{
			if (token->type == 1)
				cmd[i++] = ft_strdup(token->str);
			else if (token->type == 2)
			{
				if (token->next && token->next->str)
					in = openfile(token->next->str, 0);
				if (token->next)
					token = token->next;
				else
					break ;
			}
			else if (token->type == 3)
			{
				out = openfile(token->next->str, 1);
				if(token->next && token->next->str)
					out = openfile(token->next->str, 1);
				if (token->next)
					token = token->next;

			}
			if (token)
				token = token->next;
		}
		cmd[i] = NULL;
		addnode_back(&node, new_node(cmd, in, out));
		//free_cmds(cmd);
		if (token)
			token = token->next;
	}
	return (node);
}