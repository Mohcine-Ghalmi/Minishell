/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_clone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 11:45:48 by mghalmi           #+#    #+#             */
/*   Updated: 2023/07/22 16:29:29 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

void    echo_clone(char **cmd)
{
    int i;

    i = 1;
    if (!ft_strncmp(cmd[i], "-n", 3))
        i++;
    while (cmd[i])
        printf("%s", cmd[i++]);
    if (ft_strncmp(cmd[1], "-n", 3))
        printf("\n");
}
