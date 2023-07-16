/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:38:24 by mghalmi           #+#    #+#             */
/*   Updated: 2023/07/17 00:14:23 by mghalmi          ###   ########.fr       */
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
    char    *av[1];
    char    *av1[1];
    int     showen;
    
    (void)argc;
    (void)argv;
    av[0] = "export";
    // av[1] = "env";
    av1[0] = "env";
    showen = 0;
    new_envp = envirment(envp, &showen);
    new = struct_args(av, NULL, NULL, NULL);
    execution(new, new_envp, &showen);
    // ft_lstclear_struct(&new);
    // puts("\n---------------------------------------------");
    // new = struct_args(av1, NULL, NULL, NULL);
    // execution(new, new_envp, &showen);
    ft_lstclear_struct(&new);
    ft_lstclear_env(&new_envp);
    // atexit(fuck);
    return (0);
}
