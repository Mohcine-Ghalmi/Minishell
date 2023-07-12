/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:31:15 by selhilal          #+#    #+#             */
/*   Updated: 2023/07/13 00:28:42 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

int	main(void)
{
	char	*text;
	t_node	*node;
	t_token	*token;
	char	*tst;

	while (1)
	{
		token = NULL;
		node = NULL;
		tst = readline("> ");
		add_history(tst);
		if (parsing(tst) == 1)
		{
			text = make_spaces(tst);
			text = rem_qudes(text);
		}
		my_token(&token, text);
		node = struct_forM(token, node);
		//while (node)
		//{
		//	printf("%s,%s\n",node->cmd, node->variable);
		//	node = node->next;
		//}
		while (token)
		{
			printf("%s,%d\n",token->str, token->type);
			token = token->next;
		}
		//clear_history();
	}
}
