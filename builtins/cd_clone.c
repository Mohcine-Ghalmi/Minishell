/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_clone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:17:50 by mghalmi           #+#    #+#             */
/*   Updated: 2023/07/13 22:21:51 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

void    cd_clone(char *cmd, t_env *env)
{
    char **args;

    args = ft_split(cmd, ' ');
    if (!chdir(args[1]))
    {
        //change old PWD and curr PWD        
    }
}
