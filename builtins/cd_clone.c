/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_clone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleeps <sleeps@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:17:50 by mghalmi           #+#    #+#             */
/*   Updated: 2023/07/17 15:01:56 by sleeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

int    find_and_replace(t_env  **env, char *key, char *value)
{
    t_env   *tmp;

    tmp = *env;
    while (tmp)
    {
        if (!ft_strncmp(tmp->key, key, ft_strlen1(key)))
        {
            tmp->value  = value;
            return 1;
        }
        tmp = tmp->next;
    }
    return 0;
}

void    cd_clone(char **cmd, t_env *env)
{
    char    *oldpwd;

    if (cmd[2] != NULL)
    {
        printf("error");
        return;
    }
    oldpwd = pwd_env(env, 0);
    if (!chdir(cmd[1]))
    {
        if (!find_and_replace(&env, "OLDPWD", oldpwd))
            ft_lstadd_back_env(&env, ft_lstnew_env(ft_strdup("OLDPWD="), oldpwd, 1));
        find_and_replace(&env, "PWD", getcwd(NULL, 0));
    }
    else
        printf("minishell: cd: %s: No such file or directory\n",  cmd[1]);
}
