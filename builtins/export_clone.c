/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_clone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 22:34:08 by mghalmi           #+#    #+#             */
/*   Updated: 2023/07/17 00:18:32 by mghalmi          ###   ########.fr       */
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

void    checking_dash(char **cmd)
{
    int     i;
    int     j;

    j = 2;
    if (!cmd[1])
        while (cmd[j])
        {
            i = 0;
            while (i < first_equale(cmd[1]))
            {
                if (cmd[1][i] == '-')
                {
                    printf("export: not valid in this context:");
                    print_bdash(cmd[1], i);
                }
                i++;
            }
            j++;
        }
}

int     size_double(char **cmd)
{
    int i;

    i = 0;    
    while (cmd[i])
    {
        printf("%d %s\n", i, cmd[i]);
        i++;
    }
    return (i);
}

void    show_export(char **cmd, t_env *env, int showen)
{
    t_env	*tmp;
	int     i;

	i = 0;
	tmp = env;
	if (size_double(cmd) == 1)
    {
        while ((tmp && i < showen) && i <= showen - 1)
	    {
            printf("declare -x %s\"%s\"\n", tmp->key, tmp->value);
            tmp = tmp->next;
            i++;
	    }
    }
}

void    export_clone(char   **cmd, t_env *env, int *showen)
{
    char    *key;
    char    *value;
    int     i;

    
    i = 0;
    show_export(cmd, env, *showen);
    if (ft_strchr1(cmd[1], '='))
    {
        while (i < first_equale(cmd[1]))
        {
            if (cmd[1][i] == '-')
            {
                printf("export: not valid in this context:");
                print_bdash(cmd[1], i);
                return ;
            }
            i++;
        }
        key = ft_substr(cmd[1], 0, first_equale(cmd[1]));
		value = ft_substr(cmd[1], first_equale(cmd[1]), ft_strlen1(cmd[1]));
		ft_lstadd_back_env(&env, ft_lstnew_env(key, value));
        *showen += 1;
    }
   checking_dash(cmd);
}
