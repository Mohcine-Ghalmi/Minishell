/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:38:24 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/01 15:50:27 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

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

t_data	*ft_lstlast_cmds(t_data *lst)
{
	if (lst)
	{
		while (lst && lst->next)
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back_cmnd(t_data **list, t_data *new)
{
	if (!*list)
	{
		*list = new;
		return ;
	}
	ft_lstlast_cmds(*list)->next = new;
}

t_data  *cmds(char **cmd)
{
    int i;
    t_data  *new;

    new = NULL;
    i = 0;
    while (cmd != NULL && cmd[i])
        ft_lstadd_back_cmnd(&new, struct_args(ft_split(cmd[i++], ' '), NULL, NULL));
    return new;
}
int main(int argc, char **argv, char **envp)
{
    t_data  *new;
    t_env   *new_envp;
    char    *input;
    char **cmd;
    
    (void)argc;
    (void)argv;

    new_envp = envirment(envp);
    while (1)
    {
        input = readline("minishell>");
        if (!input)
            break;
        cmd = ft_split(input, '|');
        new = cmds(cmd);
        execution(new, new_envp);
        ft_lstclear_struct(&new);
        free_double(cmd);
        free(input);
    }
    ft_lstclear_env(&new_envp);
    return (0);
}
