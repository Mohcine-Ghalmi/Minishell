/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:38:24 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/02 10:17:02 by selhilal         ###   ########.fr       */
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
		add_history(input);
		node = inputs(input, env_exec(new_envp));
		if (node == NULL)
			continue ;
		execution(node, new_envp);
		ft_lstclear_struct(&node);
	}
	ft_lstclear_env(&new_envp);
	return (0);
}
