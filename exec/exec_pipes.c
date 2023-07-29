/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 18:34:15 by mghalmi           #+#    #+#             */
/*   Updated: 2023/07/29 16:40:20 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"
#include "exec.h"

t_data    *struct_args(char **cmd, char *infile, char *outfile)
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

void    piper_norm(t_data *cmd, int pipefd[2])
{
    close(pipefd[0]);
    if (cmd->outfile > 2)
        dup2(cmd->outfile, STDOUT_FILENO);
    else if (ft_lstsize(cmd) > 1)
	    dup2(pipefd[1], STDOUT_FILENO);
}

void	piper(t_data *cmd, t_env *new_env)
{
	pid_t	pid;
    char    **exec_enev;
    int pipefd[2];
    int b;

    b = 0;
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
        b = check_builtins(cmd->av, new_env);
        if (b < 2)
            exit(b);
        exec(cmd->av, exec_enev);
	}
    closepipe(pipefd);
}

void execution(t_data *new, t_env *envp)
{
    int status;
    unsigned int ifcond;

    ifcond = 2;
    status = 0;
    if (ft_lstsize(new) == 1)
        ifcond = first_built(new, envp);
    if (ifcond == 2)
        while  (new)
        {
            piper(new, envp);
            new = new->next;
        }
    while (wait(&status) != -1);
    if (ifcond < 2)
        update_status(ifcond, envp);
    else
        update_status(WEXITSTATUS(status), envp);
}
