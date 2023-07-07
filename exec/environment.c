/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:30:01 by mghalmi           #+#    #+#             */
/*   Updated: 2023/07/07 11:30:02 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

char **environment(char **envp)
{
    int size;
    char **new_envp;

    size = 0;
    while (envp[size])
        size++;
    new_envp = ft_calloc(sizeof(char *), size + 1);
    if (!new_envp)
        return (NULL);
    size = 0;
    while (envp[size])
    {
        new_envp[size] = ft_strdup(envp[size]);
        size++;
    } 
    return new_envp;
}

// int main(int argc, char **argv, char **envp)
// {
//     char **arr;
//     int i;

//     i = 0;
//     arr = environment(envp);
//     while (arr[i])
//         printf("%s\n", arr[i++]);
// }