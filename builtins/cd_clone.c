/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_clone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:17:50 by mghalmi           #+#    #+#             */
/*   Updated: 2023/07/10 11:40:29 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

void    update_env(char **env)
{
    
}

void    cd_clone(char *cmd, char **env)
{
    char **args;

    args = ft_split(cmd, ' ');
    if (chdir(args[1]) < 0)
    {
        
    }
}
