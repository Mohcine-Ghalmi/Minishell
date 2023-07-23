/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_clone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:45:48 by mghalmi           #+#    #+#             */
/*   Updated: 2023/07/23 18:09:00 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

int find_key(char *key, t_env *env)
{
    t_env *tmp;

    tmp = env;
    while (tmp)
    {
        if (!ft_strncmp(tmp->key, key, ft_strlen1(key)))
            return (1);
        tmp = tmp->next;
    }
    return (0);
}

void    delete_key(char *key, t_env *env)
{
    t_env *tmp;
    t_env *prev;

    prev = NULL;
    tmp = env;
    while (tmp && ft_strncmp(tmp->key, key, ft_strlen1(key)))
    {
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp)
        if (prev)
            prev->next = tmp->next;
            
    
    free(tmp);
}

void    unset_clone(t_env *env, char **cmd)
{
    int i;

    i = 1;
    while (cmd[i])
    {
        if (!find_key(cmd[i], env))
            printf("minishell: unset: `%s': not a valid identifier\n", cmd[i]);
        else
            delete_key(cmd[i], env);
        i++;
    }
}
