/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envarment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:59:52 by selhilal          #+#    #+#             */
/*   Updated: 2023/07/29 16:01:18 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

t_env        *envirment(char **old_env)
{
    int     i;
    char    *key;
    char    *value;
    t_env    *new_env;

    new_env = NULL;
    i = 0;
    while (old_env[i])
    {
        key = ft_substr(old_env[i], 0, first_equale(old_env[i]));
        value = ft_substr(old_env[i], first_equale(old_env[i]), ft_strlen1(old_env[i]));
        if (!ft_strncmp(key, "SHLVL=", 7))
            value = shlvl(value);
        ft_lstadd_back_env(&new_env, ft_lstnew_env(key, value, 1));
        i++;
    }
    ft_lstadd_back_env(&new_env, ft_lstnew_env("?=", ft_strdup(""), 3));
    if (!olpwd_env(new_env))
    {
        ft_lstadd_back_env(&new_env, ft_lstnew_env("OLDPWD", ft_strdup(""), 2));
        i++;
    }
    if (i == 1)
        new_env = empty_env(new_env);
    return (new_env);
}

t_env    *empty_env(t_env *new_env)
{
    t_env    *env;
    
    env = new_env;
    ft_lstadd_back_env(&env, ft_lstnew_env(ft_strdup("PWD="), ft_strdup(getcwd(NULL, 0)), 1));
    ft_lstadd_back_env(&env, ft_lstnew_env(ft_strdup("SHLVL="), ft_strdup("1"), 1));
    ft_lstadd_back_env(&env, ft_lstnew_env(ft_strdup("_="), ft_strdup("/user/bin/env"), 1));
    ft_lstadd_back_env(&env, ft_lstnew_env(ft_strdup("PATH="), ft_strdup("/usr/gnu/bin:/usr/local/bin:/bin:/usr/bin:."), 3));
    return (env);
}

t_env        *envirment(char **old_env)
{
    int     i;
    char    *key;
    char    *value;
    t_env    *new_env;

    new_env = NULL;
    i = 0;
    while (old_env[i])
    {
        key = ft_substr(old_env[i], 0, first_equale(old_env[i]));
        value = ft_substr(old_env[i], first_equale(old_env[i]), ft_strlen1(old_env[i]));
        if (!ft_strncmp(key, "SHLVL=", 7))
            value = shlvl(value);
        ft_lstadd_back_env(&new_env, ft_lstnew_env(key, value, 1));
        i++;
    }
    ft_lstadd_back_env(&new_env, ft_lstnew_env("?=", ft_strdup(""), 3));
    if (!olpwd_env(new_env))
    {
        ft_lstadd_back_env(&new_env, ft_lstnew_env("OLDPWD", ft_strdup(""), 2));
        i++;
    }
    if (i == 1)
        new_env = empty_env(new_env);
    return (new_env);
}

