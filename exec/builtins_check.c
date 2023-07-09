/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 14:15:43 by mghalmi           #+#    #+#             */
/*   Updated: 2023/07/09 16:32:47 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"
#include "exec.h"

int    check_builtins(char *cmd)
{
    char	*builtins[7] = {
        "echo",
        "cd",
        "pwd",
        "export",
        "unset",
        "env",
        "exit"
	};
    int i;

    i  = 0;
    while (i < 7)
    {
        if (ft_strnstr(builtins[i], cmd, ft_strlen1(cmd)))
            return 1;
        i++;
    }
    return 0;
}
