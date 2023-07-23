/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_clone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:17:50 by mghalmi           #+#    #+#             */
/*   Updated: 2023/07/23 09:31:24 by mghalmi          ###   ########.fr       */
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
            tmp->value = value;
            return 1;
        }
        tmp = tmp->next;
    }
    return 0;
}

char    *return_value(t_env *env, char *key)
{
    t_env   *tmp;

    tmp = env;
    while (tmp)
    {
        if (!ft_strncmp(tmp->key, key, ft_strlen1(key)))
            return ft_strdup(tmp->value);
        tmp = tmp->next;
    }
    return NULL;
}

void    cd_clone(char **cmd, t_env *env)
{
    char    *oldpwd;

    oldpwd = pwd_env(env, 0);
    if (cmd[1] == NULL)
    {
        if (!find_and_replace(&env, "OLDPWD", oldpwd))
            ft_lstadd_back_env(&env, ft_lstnew_env(ft_strdup("OLDPWD="), oldpwd, 1));
        find_and_replace(&env, "PWD", return_value(env, "HOME"));
        chdir(return_value(env, "HOME"));
        return;
    }
    if (!chdir(cmd[1]))
    {
        if (!find_and_replace(&env, "OLDPWD", oldpwd))
            ft_lstadd_back_env(&env, ft_lstnew_env(ft_strdup("OLDPWD="), oldpwd, 1));
        find_and_replace(&env, "PWD", getcwd(NULL, 0));
    }
    else
        printf("minishell: cd: %s: No such file or directory\n",  cmd[1]);
}
