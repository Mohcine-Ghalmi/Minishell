/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_clone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 22:34:08 by mghalmi           #+#    #+#             */
/*   Updated: 2023/07/24 18:06:04 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

int    checking_dash(char *cmd)
{
    int i;
    int len;

    i = 0;
    len =  first_equale(cmd);
    if (len == -1)
        len = ft_strlen1(cmd);
    while (i < len)
    {
        if (cmd[i] == '/' || cmd[i] == '%'
            || cmd[i] == '-' || (i < len - 1 && cmd[i] == '+' && cmd[i + 1] != '='))
        {
            printf("minishell: export: `%s` not valid identifier\n", cmd);
            return (i);
        }
        i++;
    }
    return (0);
}

int     size_double(char **cmd)
{
    int i;

    i = 0;
    while (cmd[i])
        i++;
    return (i);
}

int    show_export(char **cmd, t_env *env)
{
    t_env	*tmp;
	int     i;

	i = 0;
	tmp = env;
	if (size_double(cmd) == 1)
    {
        while (tmp)
	    {
            if (tmp->option == 2)
                printf("declare -x %s\n", tmp->key);
            else if (tmp->option <= 1)
                printf("declare -x %s\"%s\"\n", tmp->key, tmp->value);
            tmp = tmp->next;
            i++;
	    }
    }
    return (i);
}

void    add_to_env(char *cmd, t_env *env)
{
    char    *prb;
    char    *key;
    char    *value;

    key = ft_substr(cmd, 0, first_equale(cmd));
    value = ft_substr(cmd, first_equale(cmd), ft_strlen1(cmd));
    if (key[first_equale(cmd) - 2] == '+')
    {
        key = ft_substr(cmd, 0, first_equale(cmd) - 2);
        key = ft_strjoin1(key, "=");
        value = add_to_value(env, key, value);
    }
    if (find_key(key, env))
    {
        prb = ft_strjoin1("unset ", ft_substr(cmd, 0, first_equale(key) - 1));
        unset_clone(env,  ft_split(prb, ' '));
        free(prb);
    }
    ft_lstadd_back_env(&env, ft_lstnew_env(key, value, 1));
}

void    export_clone(char   **cmd, t_env *env)
{
    int     i;
    char    *key;
    char    *value;

    i = 1;
    if (!show_export(cmd, env))
    {
        while (cmd[i])
        {
            if (!option_replace(cmd[i], env))
            {
                if (ft_strchr1(cmd[i], '='))
                {
                    if (!checking_dash(cmd[i]))
                        add_to_env(cmd[i], env);
                }
                else
                    if (!checking_dash(cmd[i]))
                    {
                        key = ft_strdup(cmd[i]);
                        value = ft_strdup("");
                        ft_lstadd_back_env(&env, ft_lstnew_env(key, value, 2));
                    }
            }
            i++;
        }
    }
}
