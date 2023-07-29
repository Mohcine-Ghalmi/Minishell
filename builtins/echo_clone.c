/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_clone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 11:45:48 by mghalmi           #+#    #+#             */
/*   Updated: 2023/07/29 13:12:04 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

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
    if (!ft_strncmp(cmd[i], "-n", 3))
    {
        i++;
        flag = 1;
    }
    while (cmd[i])
    {
        if (!ft_strncmp(cmd[i], "-n", 3) && flag)
            i++;
        else
        {
            flag = 0;
            printf("%s", cmd[i++]);
        }
    }
    if (ft_strncmp(cmd[1], "-n", 3))
        printf("\n");
    return (0);
}
