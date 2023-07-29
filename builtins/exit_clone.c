/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_clone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:33:05 by mghalmi           #+#    #+#             */
/*   Updated: 2023/07/29 16:53:51 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

unsigned int     checking_status(unsigned  int status)
{
    if (status > 255)
        while (status > 255)
            status += 256;
    return (status);
}

void    update_status(unsigned int status, t_env *env)
{
    t_env *tmp;

    tmp = env;
    while (tmp)
    {
        if (!ft_strncmp("?=", tmp->key, 2))
        {
            tmp->value = ft_itoa_shlvl(checking_status(status));
            printf("exit status : %s%s\n",tmp->key ,tmp->value);
        }
        tmp = tmp->next;
    }
}

int find_char(char *str)
{
    int  i;

    i = 0;
    while (str[i])
    {
        if (str[i] < 48 || str[i] > 57)
            return (1);
        i++;
    }
    return (0);
}

int   exit_clone(t_env *env, char **cmd)
{
    if (cmd[2])
    {
        printf("exit\n");
        printf("minishell: exit: too many arguments\n");
        update_status(1, env);
        exit(1);
    }
    if (cmd[1])
    {
        if (find_char(cmd[1]))
        {
            update_status(255, env);
            printf("exit\n");
            exit(255);
        }
        update_status(checking_status(ft_atoi_shlvl(cmd[1])), env);
        printf("exit\n");
        exit(checking_status(ft_atoi_shlvl(cmd[1])));
    }
    printf("exit\n");
    update_status(0, env);
    exit(0);
    return (0);
}
