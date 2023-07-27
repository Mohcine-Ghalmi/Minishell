/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 18:34:15 by mghalmi           #+#    #+#             */
/*   Updated: 2023/07/27 18:37:23 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"
#include "exec.h"

t_data    *struct_args(char **cmd, char *infile, char *outfile, char *append)
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

void    piper_norm(t_data *cmd, int pipefd[2])
{
    close(pipefd[0]);
    if  (cmd->append > 2)
        dup2(cmd->append, STDOUT_FILENO);
    else if (cmd->outfile > 2)
        dup2(cmd->outfile, STDOUT_FILENO);
    else if (ft_lstsize(cmd) > 1)
	    dup2(pipefd[1], STDOUT_FILENO);
}

void	piper(t_data *cmd, t_env *new_env)
{
	pid_t	pid;
    char    **exec_enev;
    int pipefd[2];

    if (pipe(pipefd) < 0)
        return ;
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
        piper_norm(cmd, pipefd);
        exec_enev = env_exec(new_env);
        if (check_builtins(cmd->av, new_env))
            exit(1);
        exec(cmd->av, exec_enev);
	}
    closepipe(pipefd);
}

void execution(t_data *new, t_env *envp)
{
    int ifcond;
    int status;

    ifcond = 0;
    if (ft_lstsize(new) == 1)
        ifcond = check_builtins(new->av, envp);
        // ifcond = first_built(new, envp);
    if (ifcond == 0)
    {
        while  (new)
        {
            piper(new, envp);
            new = new->next;
        }
    }
    // while (1)
    // {
    //     waitpid(0, &status, 0);
    //     if (WEXITSTATUS(status))
    //         break;
    // }
    // replace  with waitpid(0, &status, 0)
    // check WESXITSTATUS(status)
    while (wait(NULL) != -1);
}