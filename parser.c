/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:40:30 by selhilal          #+#    #+#             */
/*   Updated: 2023/07/18 19:40:30 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

void	tokena(char *input, t_token **token, char **envp)
{
	char	*table;
	int		i;

	i = 0;
	table = NULL;
	while (input[i])
	{
		if (input[i] == '|' && input[i])
		{
			table = ft_substr(input, i, 1);
			ft_back(token, ft_lstnew(4, table));
			free(table);
			i += 1;
		}
		else if (input[i] == '>' && input[i])
			outorappand(input, &i, token);
		else if (input[i] == '<' && input[i])
			inorherdoc(input, &i, token);
		else if ((input[i] == '\"' || input[i] == '\'') && input[i])
			qudes(input, &i, token, envp);
		else if (spaces(input[i]))
			space(input, &i, token);
		else if ((!notword(input[i]) || !spaces(input[i])) && input[i])
			word(input, &i, token, envp);
	}
}

void	close_files(int in, int out)
{
	if (out > 2)
		close(out);
	if (in > 2)
		close(in);
}

t_node	*inputs(char *input, char **envp)
{
	t_token		*token;
	t_jointok	*join;
	t_lsttoken	*lst;
	t_node		*node;

	token = NULL;
	join = NULL;
	lst = NULL;
	node = NULL;
	tokena(input, &token, envp);
	free(input);
	jointok(&join, token);
	if (syntaxerror(join) == 1)
	{
		free_token(token);
		free_jointoken(join);
		return (NULL);
	}
	lst = ltoken(&join);
	node = create_node(lst);
	free_token(token);
	free_jointoken(join);
	free_lst(lst);
	return (node);
}
