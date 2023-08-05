/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:38:24 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/05 02:18:27 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

void	signl_herdoc(void)
{
	ioctl(0, TIOCSTI, "\4");
	g_test = -1;
}

int	heredoc_file(char *limiter, int outfile)
{
	char	*str;
	char	*end;

	if (outfile < 0)
		return (1);
	signal(SIGINT, signl_herdoc);
	end = ft_strjoin(limiter, "\n");
	str = readline("> ");
	if (!str)
		return (1);
	while (end && ft_strncmp(end, str, ft_strlen(str) - 1)) 
	{
		str = ft_strjoin(str, "\n");
		if (str == NULL)
			return (1);
		ft_putstr_fd(str, outfile);
		free(str);
		str = readline("> ");
	}
	free(end);
	free(str);
	close(outfile);
	if (g_test == -1)
		return (1);
	return (0);
}

int	heredoc(char *limiter)
{
	int	fd[2];

	pipe(fd);
	g_test = 0;
	if (fd < 0)
		return (0);
	if (heredoc_file(limiter, fd[1]))
		return (-1);
	return (fd[0]);
}

int	heredocfile(t_lsttoken **token, int in)
{
	if (g_test != -1)
		in = heredoc((*token)->next->str);
	if ((*token)->next)
		(*token) = (*token)->next;
	return (in);
}

int	main(int argc, char **argv, char **envp)
{
	t_node	*node;
	t_env	*new_envp;
	char	*input;

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
		g_test = 0;
		input = readline("minishell> ");
		if (!input)
			exit_main();
		if (input[0] == '\0')
		{
			free(input);
			continue ;
		}
		if (qudespars(input) == 0)
		{
			ft_putstr_fd("syntax error close qudes\n", 2);
			update_status(258, new_envp, 0);
			free(input);
			continue ;
		}
		add_history(input);
		node = inputs(input, env_exec(new_envp));
		if (node == NULL)
		{
			update_status(258, new_envp, 0);
			continue ;
		}
		execution(node, new_envp);
		if (g_test == -1)
			update_status(1, new_envp, 1);
		ft_lstclear_struct(&node);
	}
	return (ft_lstclear_env(&new_envp), 0);
}
