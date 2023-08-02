/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:38:24 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/02 01:45:06 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_node	*node;
	t_env	*new_envp;
	char	*input;

	(void)argv;
	if (argc > 2)
		return (0);
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
	new_envp = envirment(envp);
	while (1)
	{
		node = NULL;
		input = readline("minishell>");
		if (!input)
			exit_main();
		add_history(input);
		node = inputs(input, env_exec(new_envp));
		if (node == NULL)
			continue ;
		execution(node, new_envp);
		clear_history();
		ft_lstclear_struct(&node);
	}
	ft_lstclear_env(&new_envp);
	return (0);
}
