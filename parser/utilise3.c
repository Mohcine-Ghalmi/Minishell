/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilise3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 22:50:36 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/06 23:56:45 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	filein(t_lsttoken **token, int in)
{
	in = openfile((*token)->next->str, STDIN_FILENO);
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

int	appendfile(int *flagout, t_lsttoken **token, int out)
{
	if (*flagout != -1)
	{
		out = append((*token)->next->str);
		*flagout = out;
	}
	if ((*token)->next)
		(*token) = (*token)->next;
	return (out);
}

void	init_values(int *in, int *out)
{
	*in = 0;
	*out = 1;
}
