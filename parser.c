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
	int		i;

	i = 0;
	while (input != NULL && input[i])
	{
		if (input[i] == '|' && input[i])
		{
			ft_back(token, ft_lstnew(4, ft_substr(input, i, 1)));
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
		else if ((!notword(input[i]) || !spaces(input[i])))
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

t_node	*inputs(char *input, char **envp, int *ret)
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
		free_token(&token);
		free_jointoken1(&join);
		return (free_double(envp), NULL);
	}
	lst = ltoken(&join);
	*ret = create_node(lst, &node, envp);
	free_lst(&lst);
	free_jointoken(&join);
	free_token(&token);
	free_double(envp);
	return (node);
}

char	*get_user_input(t_node *node, t_env *new_envp)
{
	char	*input;

	node = NULL;
	rl_catch_signals = 0;
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
	g_test = 0;
	input = readline("minishell> ");
	if (g_test == -2)
		update_status(1, new_envp, 1);
	g_test = 0;
	return (input);
}
