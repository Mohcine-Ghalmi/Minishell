/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilise3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 22:50:36 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/04 17:12:58 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	filein(int *flagin, t_lsttoken **token, int in)
{
	if (*flagin != -1)
	{
		in = openfile((*token)->next->str, STDIN_FILENO);
		*flagin = in;
	}
	if ((*token)->next)
		(*token) = (*token)->next;
	return (in);
}

int	fileout(int *flagout, t_lsttoken **token, int out)
{
	if (*flagout != -1)
	{
		out = openfile((*token)->next->str, STDOUT_FILENO);
		*flagout = out;
	}
	if ((*token)->next)
		(*token) = (*token)->next;
	return (out);
}

int	heredocfile(t_lsttoken **token, int in)
{
	in = heredoc((*token)->next->str);
	if ((*token)->next)
		(*token) = (*token)->next;
	return (in);
}

int	appendfile(t_lsttoken **token, int out)
{
	out = append((*token)->next->str);
	if ((*token)->next)
		(*token) = (*token)->next;
	return (out);
}

void	init_values(int *i, int *in, int *out)
{
	*i = 0;
	*in = 0;
	*out = 1;
}
