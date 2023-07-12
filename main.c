/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:31:15 by selhilal          #+#    #+#             */
/*   Updated: 2023/07/12 23:22:32 by selhilal         ###   ########.fr       */
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
		//clear_history();
	}
}
