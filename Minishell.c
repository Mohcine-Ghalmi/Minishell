/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleeps <sleeps@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:38:24 by mghalmi           #+#    #+#             */
/*   Updated: 2023/07/17 02:58:56 by sleeps           ###   ########.fr       */
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
    char    *av[4];
    char    *av1[2];
    char    *av3[2];
    int     showen;
    
    (void)argc;
    (void)argv;
    av[0] = "export";
    av[1] = "ajsdhkj";
    av[2] = "a=5";
    av[3] = NULL;
    av1[0] = "export";
    av1[1] = NULL;
    av3[0] = "env";
    av3[1] = NULL;
    showen = 0;
    new_envp = envirment(envp, &showen);
    new = struct_args(av, NULL, NULL, NULL);
    execution(new, new_envp, &showen);
    ft_lstclear_struct(&new);
    puts("\n---------------------------------------------");
    new = struct_args(av1, NULL, NULL, NULL);
    execution(new, new_envp, &showen);
    ft_lstclear_struct(&new);
    puts("\n---------------------------------------------");
    new = struct_args(av3, NULL, NULL, NULL);
    execution(new, new_envp, &showen);
    ft_lstclear_struct(&new);
    ft_lstclear_env(&new_envp);
    // atexit(fuck);
    return (0);
}
