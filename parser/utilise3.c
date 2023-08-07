/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilise3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 22:50:36 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/08 00:25:53 by mghalmi          ###   ########.fr       */
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

char	*extract_dollar_value(char *text, int *j, char **envp, int	*k)
{
	int		t;
	char	*tex;

	t = 0;
	t = *j;
	tex = NULL;
	while (text[*j] && !notword(text[*j])
		&& !spaces(text[*j]) && text[*j] != '$')
		*j += 1;
	*k = *j;
	if (text[*j] && text[*j] == '$')
		tex = dollar(text, j, envp);
	return (tex);
}
