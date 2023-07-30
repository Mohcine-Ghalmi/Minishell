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
		join = NULL;
		lst = NULL;
		node = NULL;
		input = readline("> ");
		if (input[0] == '\0')
			break ;
		add_history(input);
		if (qudespars(input) == 0)
		{
			ft_putstr_fd("syntax error close qudes\n", 2);
			continue ;
		}
		tokena(input, &token, envp);
		free(input);
		jointok(&join, token);
		//syntaxerror(join);
		lst = ltoken(&join);
		node = create_node(lst);
		while (node)
		{
			//printf("%s, %d\n",token->cmd, token->type);
			//token = token->next;
			int i = 0;
			while (node->cmd[i])
			{
				printf("s = %s\n",node->cmd[i]);
				i++;
			}
			printf("%d,%d\n", node->fdin, node->fdout);
			//close_files(node->fdin, node->fdout);
			node = node->next;
		}
		free_token(token);
		free_jointoken(join);
		free_lst(lst);
		free_node(node);
	}
}
