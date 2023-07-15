/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:38:24 by mghalmi           #+#    #+#             */
/*   Updated: 2023/07/15 18:11:04 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

t_data  *pipes_cmnds()
{
    t_data *new;

    new = struct_args("env", NULL, NULL, NULL);
    // new->next = struct_args("sort", NULL, NULL, NULL);
    // new->next->next = struct_args("ls", NULL, NULL, NULL);
    return new;
}

void    fuck(void)
{
    system("leaks minishell");
}

int main(int argc, char **argv, char **envp)
{
    t_data  *new;
    t_env   *new_envp;
    char    *input;
    int main_fork;
    
    (void)argc;
    (void)argv;
    new_envp = envirment(envp);
    while(1)
    {
        input = readline("$ ");
        new = struct_args(input, NULL, NULL, NULL);
        main_fork = fork();
        if (main_fork)
            execution(new, new_envp);
        // else
        //     exit(1);
        ft_lstclear_struct(&new);
        waitpid(0, 0, 0);
    }
    ft_lstclear_env(&new_envp);
    // atexit(fuck);
    return (0);
}
