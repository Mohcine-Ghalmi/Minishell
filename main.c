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

#include"minishell.h"

void	tokena(char *input, t_token **token, char **envp)
{
	char	*table;
	int		i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '|' && input[i])
		{
			table = ft_substr(input, i, 1);
			ft_lstadd_back(token, ft_lstnew(4, table));
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

void	free_node(t_node **node)
{
	t_node *tmp;

	tmp = *node;
	while ((*node))
	{
		tmp = (*node)->next;
		free((*node));
		(*node) = tmp;
	}
	free(tmp);
}

void	free_jointoken(t_jointok **token)
{
	t_jointok *tmp;

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
	t_token *tmp;

	tmp = *token;
	while ((*token))
	{
		tmp = (*token)->next;
		free((*token));
		(*token) = tmp;
	}
	free(tmp);
}

int	main(int argc, char **argv, char **envp)
{
	char		*input;
	t_token		*token;
	t_jointok	*join;
	t_lsttoken	*lst;
	t_node		*node;

	(void)argc;
	(void)argv;
	while (1)
	{
		token = NULL;
		input = readline("> ");
		if (qudespars(input) == 0)
		{
			printf("syntax error close qudes\n");
			free(input);
			continue ;
		}
		tokena(input, &token, envp);
		jointok(&join, token);
		//syntaxerror(join);
		//	continue;
		lst = ltoken(&join);
		//node = create_node(lst);
		while (lst)
		{
			printf("%s,%d\n", lst->str,lst->type);
			lst = lst->next;
		}
		//free_node(&node);

		free_jointoken(&join);
		free_token(&token);
	}
}