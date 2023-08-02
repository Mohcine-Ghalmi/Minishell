/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_clone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:33:05 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/01 22:57:57 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

unsigned int     checking_status(unsigned  int status)
{
    if (status > 255)
        while (status > 255)
            status -= 256;
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
            tmp->option = 3;
            break;
        }
        tmp = tmp->next;
    }
}

int find_char(char *str)
{
    int  i;

    i = 0;
    if (!str)
        return (1);
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
        if (!find_char(cmd[1]))
        {
            ft_putstr_fd("exit\n", 2);
            ft_putstr_fd("minishell: exit: too many arguments\n", 2);
            update_status(1, env);
            return (1);
        }
    }
    if (cmd[1])
    {
        if (find_char(cmd[1]))
        {
            update_status(255, env);
            printf("exit\n");
            ft_putstr_fd("minishell: exit: ", 2);
            ft_putstr_fd(cmd[1], 2);
            ft_putstr_fd(": numeric argument required\n", 2);
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
