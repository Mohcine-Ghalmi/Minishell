/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 18:34:15 by mghalmi           #+#    #+#             */
/*   Updated: 2023/06/24 23:36:16 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

t_data    *struct_args(char *cmd, char *infile, char *outfile)
{
    t_data *new;

    new = malloc(sizeof(t_data));
    new->av = cmd;
    new->infile = openfile(infile, 0);
    new->outfile = openfile(outfile, 1);
    new->next = NULL;
    return new;
}

int	ft_lstsize(t_data *lst)
{
	int	len;

	if (!lst)
		return (0);
	len = 0;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

int    create_pipes(int pipes[2])
{
    if (pipe(pipes) < 2)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

void	pipex_test(t_data *cmd, char **env)
{
	pid_t	pid;
    int pipefd[2];

    pipe(pipefd);
	pid = fork();
	if (pid)
	{
		close(pipefd[1]);
        if (cmd->infile > 2)
            dup2(cmd->infile, STDIN_FILENO);
        else
		    dup2(pipefd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
	else
	{
		close(pipefd[0]);
        if (cmd->outfile > 2)
            dup2(cmd->outfile, STDOUT_FILENO);
        else if (ft_lstsize(cmd) > 1)
		    dup2(pipefd[1], STDOUT_FILENO);
		exec(cmd->av, env);
	}
    closepipe(pipefd);
}

void execution(t_data *new, char **envp)
{
    while  (new)
    {
        pipex_test(new, envp);
        new = new->next;
    }
}

int main(int argc, char **argv, char **envp)
{
    t_data *new;
    // char    *stock;
    // int main_fork;
    char **new_envp;

    (void)argc;
    (void)argv;
    // while (1)
    // {
        // stock = readline("$ ");
        new_envp = environment(envp);
        new = struct_args("cat", NULL, NULL);
        new->next = struct_args("ls", NULL, NULL);
        new->next->next = struct_args("top", NULL, NULL);
        // if (!ft_strncmp(stock, "exit", 5))
        //     exit(1);
        // main_fork = fork();
        // if (!main_fork)
        // {
            execution(new, new_envp);
            // exec(new->av, new_envp);
            // exit(1);
        // }
        // waitpid(0, 0, 0);
    // }
    free(new);
    free(new_envp);
    return 0;
}