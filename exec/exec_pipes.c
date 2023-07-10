/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 18:34:15 by mghalmi           #+#    #+#             */
/*   Updated: 2023/07/10 10:39:05 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"
#include "exec.h"

t_data    *struct_args(char *cmd, char *infile, char *outfile, char *append)
{
    t_data *new;

    new = malloc(sizeof(t_data));
    new->av = cmd;
    new->infile = openfile(infile, 0);
    new->outfile = openfile(outfile, 1);
    new->append = open(append, O_CREAT | O_RDWR | O_APPEND, 0777);
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
	}
	else
	{
		close(pipefd[0]);
        if  (cmd->append > 2)
            dup2(cmd->append, STDOUT_FILENO);
        else if (cmd->outfile > 2)
            dup2(cmd->outfile, STDOUT_FILENO);
        else if (ft_lstsize(cmd) > 1)
		    dup2(pipefd[1], STDOUT_FILENO);
        check_builtins(cmd->av, env);
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
    while (wait(NULL) != -1);
}
