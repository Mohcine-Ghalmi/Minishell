/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:38:24 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/04 21:04:40 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

// int	main(int argc, char **argv, char **envp)
// {
// 	t_node	*node;
// 	t_env	*new_envp;
// 	char	*input;

// 	(void)argv;
// 	if (argc > 1)
// 		return (printf("no arguments\n"), 0);
// 	new_envp = envirment(envp);
// 	while (1)
// 	{
// 		node = NULL;
// 		rl_catch_signals = 0;
// 		signal(SIGINT, sigint_handler);
// 		signal(SIGQUIT, SIG_IGN);
// 		g_test = 0;
// 		input = readline("minishell> ");
// 		if (!input)
// 			exit_main();
// 		if (input[0] == '\0')
// 		{
// 			free(input);
// 			continue ;
// 		}
// 		if (qudespars(input) == 0)
// 		{
// 			ft_putstr_fd("syntax error close qudes\n", 2);
// 			update_status(258, new_envp, 0);
// 			free(input);
// 			continue ;
// 		}
// 		add_history(input);
// 		node = inputs(input, env_exec(new_envp));
// 		if (node == NULL)
// 		{
// 			update_status(258, new_envp, 0);
// 			continue ;
// 		}
// 		execution(node, new_envp);
// 		ft_lstclear_struct(&node);
// 	}
// 	return (ft_lstclear_env(&new_envp), 0);
// }
