/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_clone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleeps <sleeps@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 13:01:36 by mghalmi           #+#    #+#             */
/*   Updated: 2023/07/28 16:47:58 by sleeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

char    *pwd_env(t_env   *new_env, int ret)
{
    t_env   *tmp;

    tmp = new_env;
    while(tmp)
    {
        if (!ft_strncmp(tmp->key, "PWD=", ft_strlen1(tmp->key)))
        {
            if (ret == 1)
                printf("%s\n", tmp->value);
            exit(0);
        }
        tmp = tmp->next;
    }
    return (tmp->value);
}

void    pwd_clone(char  **cmd, t_env *new_env)
{
    char    *ret;

    ret = getcwd(NULL, 0);
    if (cmd[1])
    {
        printf("pwd with no options\n");
        free(ret);
        exit(0);
    }
    if (ret !=  NULL)
    {
        printf("%s\n",  ret);
        exit(0);
    }
    else
        pwd_env(new_env, 1);
    free(ret);
}
