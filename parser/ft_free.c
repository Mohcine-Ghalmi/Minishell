/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:20:52 by selhilal          #+#    #+#             */
/*   Updated: 2023/08/08 18:41:54 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	free_node(t_node *node)
{
	t_node	*tmp;

	tmp = node;
	while ((node))
	{
		tmp = (node)->next;
		free_double(node->cmd);
		free((node));
		(node) = tmp;
	}
	free(tmp);
}

void	free_lst(t_lsttoken **lst)
{
	t_lsttoken	*tmp;

	tmp = *lst;
	while ((*lst))
	{
		tmp = (*lst)->next;
		if ((*lst)->type != 7)
			free((*lst)->str);
		free((*lst));
		(*lst) = tmp;
	}
	free(tmp);
}

void	free_jointoken1(t_jointok **token)
{
	t_jointok	*tmp;

	tmp = *token;
	while ((*token))
	{
		tmp = (*token)->next;
		if ((*token)->type != 10)
			free((*token)->str);
		free((*token));
		(*token) = tmp;
	}
	free(tmp);
}

void	free_jointoken(t_jointok **token)
{
	t_jointok	*tmp;

	tmp = *token;
	while ((*token))
	{
		tmp = (*token)->next;
		free((*token));
		(*token) = tmp;
	}
	free(tmp);
}

void	free_token(t_token **token)
{
	t_token	*tmp;

	tmp = *token;
	while ((*token))
	{
		tmp = (*token)->next;
		if ((*token)->type == 1 || (*token)->type == 10 \
			|| (*token)->type == 5 || (*token)->type == 7
			|| (*token)->type == 6)
			free((*token)->cmd);
		free((*token));
		(*token) = tmp;
	}
}
