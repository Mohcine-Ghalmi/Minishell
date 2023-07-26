/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:38:24 by mghalmi           #+#    #+#             */
/*   Updated: 2023/07/26 17:06:12 by mghalmi          ###   ########.fr       */
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
    char    *input;
    char **cmd;
    
    (void)argc;
    (void)argv;

    new_envp = envirment(envp);
    while (1)
    {
        input = readline("minishell>");
        cmd = ft_split(input, ' ');
        new = struct_args(cmd, NULL, NULL, NULL);
        execution(new, new_envp);
        ft_lstclear_struct(&new);
        free_double(cmd);
        free(input);
    }
    ft_lstclear_env(&new_envp);
    // atexit(fuck);
    return (0);
}
