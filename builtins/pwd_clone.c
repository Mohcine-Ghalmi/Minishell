/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_clone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 13:01:36 by mghalmi           #+#    #+#             */
/*   Updated: 2023/07/14 16:44:43 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

void    pwd_env(t_env   *new_env)
{
    t_env   *tmp;

    tmp = new_env;
    while(tmp)
    {
        if (ft_strnstr(tmp->key, "env", ft_strlen1(tmp->key)))
            printf("%s\n", tmp->value);
        tmp = tmp->next;
    }
}

void    pwd_clone(char  **cmd, t_env *new_env)
{
    char    *ret;

    ret = getcwd(NULL, 0);
    if (cmd[1] && cmd[1][0] == '-')
    {
        printf("pwd with no options\n");
        free(ret);
        return ;
    }
    if (ret !=  NULL)
        printf("%s\n",  ret);
    else
        pwd_env(new_env);
    free(ret);
}
