/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:38:24 by mghalmi           #+#    #+#             */
/*   Updated: 2023/07/22 19:47:37 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

void    fuck(void)
{
    system("leaks minishell");
}

int main(int argc, char **argv, char **envp)
{
    t_data  *new;
    t_env   *new_envp;
    char    *av[7];
    
    (void)argc;
    (void)argv;
    av[0] = "echo";
    av[1] = "-n";
    av[2] = "hello1 ";
    av[3] = "hello2 ";
    av[4] = "hello3 ";
    av[5] = NULL;

    new_envp = envirment(envp);
    new = struct_args(av, NULL, NULL, NULL);
    execution(new, new_envp);
    ft_lstclear_struct(&new);
    ft_lstclear_env(&new_envp);
    // atexit(fuck);
    return (0);
}
