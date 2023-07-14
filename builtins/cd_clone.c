/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_clone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:17:50 by mghalmi           #+#    #+#             */
/*   Updated: 2023/07/14 18:47:33 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

void    find_and_replace(t_env  *env, char *key, char *value)
{
    t_env   *tmp;

    tmp = env;
    while (tmp)
    {
        if (ft_strncmp(tmp->key, key, ft_strlen1(key)))
        {
            free(tmp->value);
            tmp->value  = ft_strdup1(value);
        }
    }
}

void    cd_clone(char *cmd, t_env *env)
{
    char **args;
    char    *oldpwd;

    args = ft_split(cmd, ' ');
    if (args[2] != NULL)
    {
        printf("error");
        return;
    }
    oldpwd = pwd_env(env);
    if (!chdir(args[1]))
    {
        find_and_replace(env, "OLDPWD", oldpwd);
        find_and_replace(env, "PWD", getcwd(NULL, 0));
    }
}
