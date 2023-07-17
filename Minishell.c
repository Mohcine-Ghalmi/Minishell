/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleeps <sleeps@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:38:24 by mghalmi           #+#    #+#             */
/*   Updated: 2023/07/17 18:26:18 by sleeps           ###   ########.fr       */
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
    char    *av[3];
    char    *av1[2];
    
    (void)argc;
    (void)argv;
    av[0] = "export";
    av[1] = "PWD=";
    av[2] = NULL;

    av1[0] = "export";
    av1[1] = NULL;
    new_envp = envirment(envp);
    new = struct_args(av, NULL, NULL, NULL);
    execution(new, new_envp);
    ft_lstclear_struct(&new);
    new = struct_args(av1, NULL, NULL, NULL);
    execution(new, new_envp);
    ft_lstclear_struct(&new);
    ft_lstclear_env(&new_envp);
    // atexit(fuck);
    return (0);
}
