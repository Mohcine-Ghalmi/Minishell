/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 03:16:50 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/19 20:05:07 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

void	for_exec(t_node *node, t_env *new_envp)
{
	execution(node, new_envp);
	if (g_test == -1)
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
	return (inputs(input, env_exec(new_envp), ret));
}

int	to_con(char *input, t_env *new_envp)
{
	int	i;

	i = 0;
	add_history(input);
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

void	execute_minishell(t_env	*new_envp)
{
	t_node	*node;
	char	*input;
	int		ret;

	ret = 0;
	node = NULL;
	while (1)
	{
		input = get_user_input(node, new_envp);
		if (!input)
			exit_main(new_envp);
		if (to_con(input, new_envp))
			continue ;
		node = in_hist(input, new_envp, &ret);
		if (node == NULL)
		{
			update_status(258, new_envp, 0);
			continue ;
		}
		if (ret != -1)
			for_exec(node, new_envp);
		for_stats(new_envp, node, ret);
		free_node(node);
		ft___pwd(new_envp);
	}
}
