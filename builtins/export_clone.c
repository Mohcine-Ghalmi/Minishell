/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_clone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleeps <sleeps@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 22:34:08 by mghalmi           #+#    #+#             */
/*   Updated: 2023/07/17 18:27:37 by sleeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

void    print_bdash(char *str, int i)
{
    int j;

    j = 0;
    while (j <= i)
        printf("%c", str[j++]);
}

int    checking_dash(char *cmd)
{
    int i;

    i = 0;
    while (i < first_equale(cmd))
    {
        if (cmd[i] == '-')
        {
            printf("export: not valid in this context:");
            print_bdash(cmd, i);
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
            if (!ft_strncmp(tmp->value, "-1", 2))
                printf("declare -x %s\n", tmp->key);
            else if (ft_strncmp(tmp->value, "-2", 2))
                printf("declare -x %s\"%s\"\n", tmp->key, tmp->value);
            tmp = tmp->next;
            i++;
	    }
    }
    return (i);
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
                if (ft_strchr1(cmd[i], '='))
                {
                    if (!checking_dash(cmd[i]))
                    {
                        key = ft_substr(cmd[i], 0, first_equale(cmd[i]));
                        value = ft_substr(cmd[i], first_equale(cmd[i]), ft_strlen1(cmd[i]));
                        ft_lstadd_back_env(&env, ft_lstnew_env(key, value, 1));
                    }
                }
                else
                    if (!checking_dash(cmd[i]))
                    {
                        key = ft_strdup(cmd[i]);
                        value = ft_strdup("-1");
                        ft_lstadd_back_env(&env, ft_lstnew_env(key, value, 0));
                    }
            i++;
        }
    }
}
