/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:38:24 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/03 18:01:55 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_node	*node;
	t_env	*new_envp;
	char	*input;

	(void)argv;
	if (argc > 1)
		return (printf("no arguments\n"), 0);
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
	new_envp = envirment(envp);
	while (1)
	{
		node = NULL;
		input = readline("\033[31;1mminishell>\033[0m");
		if (!input)
			exit_main();
		if (qudespars(input) == 0)
		{
			ft_putstr_fd("syntax error close qudes\n", 2);
			free(input);
			continue ;
		}
		add_history(input);
		node = inputs(input, env_exec(new_envp));
		if (node == NULL)
			continue ;
		execution(node, new_envp);
		ft_lstclear_struct(&node);
	}
	return (ft_lstclear_env(&new_envp), 0);
}
