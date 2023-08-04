/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilise3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 22:50:36 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/04 22:54:14 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int g_test;

void signl_herdoc()
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
	while (end && ft_strncmp(end, str, ft_strlen(end) - 1)) 
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
		return(1);
	return(0);
}

int	heredoc(char *limiter)
{
	int	fd[2];

	pipe(fd);
	g_test = 0;
	if (fd < 0)
		return (0);
	if(heredoc_file(limiter, fd[1]))
		return(-1);
	return (fd[0]);
}


int	filein(int *flagin, t_lsttoken **token, int in)
{
	if (*flagin != -1)
	{
		in = openfile((*token)->next->str, STDIN_FILENO);
		*flagin = in;
	}
	if ((*token)->next)
		(*token) = (*token)->next;
	return (in);
}

int	fileout(int *flagout, t_lsttoken **token, int out)
{
	if (*flagout != -1)
	{
		out = openfile((*token)->next->str, STDOUT_FILENO);
		*flagout = out;
	}
	if ((*token)->next)
		(*token) = (*token)->next;
	return (out);
}

int	heredocfile(t_lsttoken **token, int in)
{
	if (g_test != -1)
		in = heredoc((*token)->next->str);
	if ((*token)->next)
		(*token) = (*token)->next;
	return (in);
}

int	appendfile(t_lsttoken **token, int out)
{
	out = append((*token)->next->str);
	if ((*token)->next)
		(*token) = (*token)->next;
	return (out);
}

void	init_values(int *i, int *in, int *out)
{
	*i = 0;
	*in = 0;
	*out = 1;
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
		char **my = env_exec(new_envp);
		add_history(input);
		// printf("before input char env\n");
		// show_env_char(my);
		// printf("before input lst env\n");
		// show_env_lst(new_envp);
		// printf("inpuit === %s\n", input);
		node = inputs(input, my);
		
		if (node == NULL)
		{
			update_status(258, new_envp, 0);
			continue ;
		}
		// printf("befoeree exe\n");
		// show_env_lst(new_envp);
		execution(node, new_envp);
		// printf("after exe\n");
		// show_env_lst(new_envp);
		ft_lstclear_struct(&node);
	}
	return (ft_lstclear_env(&new_envp), 0);
}

