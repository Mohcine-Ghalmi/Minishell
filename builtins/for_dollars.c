/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_dollars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:15:36 by mghalmi           #+#    #+#             */
/*   Updated: 2023/07/15 14:59:47 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

void    out_dollars(char *key, t_env *new_env)
{
    t_env   *tmp;
    int aff;

    aff = 0;
    tmp = new_env;
    while (tmp)
    {
        if (!ft_strncmp(key, tmp->key, ft_strlen1(key)))
        {
            aff = 1;
            printf("%s\n", tmp->value);
            return ;
        }
        tmp = tmp->next;
    }
    if (!aff)
        printf("\n");
}
