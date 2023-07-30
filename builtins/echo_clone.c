/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_clone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 11:45:48 by mghalmi           #+#    #+#             */
/*   Updated: 2023/07/30 17:40:56 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

int option_echo(char *str)
{
    int i;

    i = 0;
    if (str[i] == '-')
        i++;
    while (str[i])
    {
        if (str[i] != 'n')
            return (1);
        i++;
    }
    return (0);
}

int double_size(char **str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

int    echo_clone(char **cmd)
{
    int i;
    int flag;

    i = 1;
    flag = 0;
    if (!cmd[i])
    {
        printf("\n");
        return (0);
    }
    while (cmd[i])
    {
        if (!option_echo(cmd[i]))
            flag = 1;
        if (option_echo(cmd[i]))
            printf("%s", cmd[i]);
        if (i < double_size(cmd) - 1)
            printf(" ");
        i++;
    }
    if (!flag)
        printf("\n");
    return (0);
}
