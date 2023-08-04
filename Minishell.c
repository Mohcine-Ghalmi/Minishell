/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:38:24 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/04 05:40:33 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_node	*node;
	t_env	*new_envp;
	char	*input;
	char  **env_exc;

	(void)argv;
	if (argc > 1)
		return (printf("no arguments\n"), 0);
	new_envp = envirment(envp);
	while (1)
	{
		node = NULL;
		rl_catch_signals = 0;
		signal(SIGINT, sigint_handler);
		signal(SIGQUIT, SIG_IGN);
		input = readline("minishell>");
		if (!input)
			exit_main();
		if(input)
			signal(SIGINT, sigint_handler);
		if (qudespars(input) == 0)
		{
			ft_putstr_fd("syntax error close qudes\n", 2);
			free(input);
			continue ;
		}
		add_history(input);
		env_exc = env_exec(new_envp);
		node = inputs(input, env_exc);
		if (node == NULL)
			continue ;
		// execution(node, new_envp);
		ft_lstclear_struct(&node);
	}
	return (ft_lstclear_env(&new_envp), 0);
}
