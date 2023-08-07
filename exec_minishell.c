/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 03:16:50 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/07 16:57:25 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

void	for_exec(t_node *node, t_env *new_envp)
{
	execution(node, new_envp);
	if (g_test == -1 || g_test == 4)
		update_status(1, new_envp, 1);
}

void	for_qudespars(t_env *new_envp, char *input)
{
	ft_putstr_fd("syntax error close qudes\n", 2);
	update_status(258, new_envp, 0);
	free(input);
}

t_node	*in_hist(char *input, t_env *new_envp, int	*ret)
{
	add_history(input);
	return (inputs(input, env_exec(new_envp), ret));
}

int	to_con(char *input, t_env *new_envp)
{
	int	i;

	i = 0;
	if (input[0] == '\0')
	{
		free(input);
		i = 1;
	}
	if (qudespars(input) == 0)
	{
		for_qudespars(new_envp, input);
		i = 1;
	}
	return (i);
}

void	execute_minishell(t_env *new_envp)
{
	t_node	*node;
	char	*input;
	int		ret;

	ret = 0;
	while (1)
	{
		input = get_user_input(node);
		if (!input)
			exit_main();
		if (to_con(input, new_envp))
			continue ;
		node = in_hist(input, new_envp, &ret);
		if (node == NULL)
		{
			if (ret != -1)
				update_status(258, new_envp, 0);
			continue ;
		}
		for_exec(node, new_envp);
		free_node(node);
		if (ret == -1)
			update_status(1, new_envp, 0);
	}
}
