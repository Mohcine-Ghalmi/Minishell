/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_clone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:33:05 by mghalmi           #+#    #+#             */
/*   Updated: 2023/07/25 14:44:44 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

int     checking_status(int status)
{
    
}

void    update_status(int status, t_env *env)
{
    t_env *tmp;

    tmp = env;
    while (tmp)
    {
        if (!ft_strncmp("?", tmp->key, 2))
            tmp->value = ft_itoa_shlvl(status);
        tmp = tmp->next;
    }
}

void    exit_clone(t_env *env, char **cmd)
{
    (void)env;
    (void)cmd;
    printf("exit\n");
    exit(1);
}
