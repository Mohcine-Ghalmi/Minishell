/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 18:34:15 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/02 04:41:20 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"
#include "exec.h"

// int	ft_lstsize(t_node *lst)
// {
// 	int	len;

// 	if (!lst)
// 		return (0);
// 	len = 0;
// 	while (lst)
// 	{
// 		len++;
// 		lst = lst->next;
// 	}
// 	return (len);
// }

void    piper_norm(t_node *cmd, int pipefd[2])
{
    close(pipefd[0]);
    if (cmd->fdout > 2)
        dup2(cmd->fdout, STDOUT_FILENO);
    else if (ft_lstsize_node(cmd) > 1)
	    dup2(pipefd[1], STDOUT_FILENO);
    close(pipefd[1]);
}

void	piper(t_node *cmd, t_env *new_env)
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
        if (cmd->fdin > 2)
            dup2(cmd->fdin, STDIN_FILENO);
        else
		    dup2(pipefd[0], STDIN_FILENO);
	}
	else
	{
        piper_norm(cmd, pipefd);
        exec_enev = env_exec(new_env);
        b = check_builtins(cmd->cmd, new_env);
        if (b < 2)
            exit(b);
        exec(cmd->cmd, exec_enev);
	}
    closepipe(pipefd);
}

void execution(t_node *new, t_env *envp)
{
    int status;
    unsigned int ifcond;
    int in;
    int out;

    ifcond = 2;
    status = 0;
    in = dup(0);
    out = dup(1);
    if (ft_lstsize_node(new) == 1)
        ifcond = first_built(new, envp);
    if (ifcond == 2)
    {
        dup2(new->fdin, STDIN_FILENO);
        while  (new)
        {
            piper(new, envp);
            new = new->next;
        }
    }
    dup2(in, STDIN_FILENO);
    dup2(out, STDOUT_FILENO);
    while (wait(&status) != -1);
    if (ifcond < 2)
        update_status(ifcond, envp);
    else
        update_status(WEXITSTATUS(status), envp);
}
