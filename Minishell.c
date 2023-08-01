/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:38:24 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/01 19:16:46 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

void    free_all(t_node  **new, char *input)
{
    ft_lstclear_struct(new);
    free(input);
}

int main(int argc, char **argv, char **envp)
{
    t_node   *node;
    t_env   *new_envp;
    char    *input;
    int         to_move;
    
    (void)argv;
    if (argc > 2)
        return (0);
    signal(SIGINT, sigint_handler);
    signal(SIGQUIT, SIG_IGN);
    new_envp = envirment(envp);
    while (1)
    {
        node = NULL;
        input = readline("minishell>");
        if (!input)
            exit_main();
        add_history(input);
        node = inputs(input, envp, &to_move);
        if (to_move == 1)
            continue ;
        while(node)
        {
            execution(node, new_envp);
            node = node->next;
        }
        clear_history();
        free_all(&node, input);
    }
    ft_lstclear_env(&new_envp);
    return (0);
}
