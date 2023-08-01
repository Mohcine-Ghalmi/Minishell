/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:57:16 by selhilal          #+#    #+#             */
/*   Updated: 2023/08/01 14:24:11 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

void    heredoc_file(char *limiter, int outfile)
{
    char    *str;
    char    *end;

    if (outfile < 0)
        exit(1);
    end = ft_strjoin(limiter, "\n");
    str = readline("> ");
    while (end && ft_strncmp(end, str, ft_strlen(str)))
    {
        ft_putstr_fd(str, outfile);
        free(str);
        str = readline("> ");
    }
    free(end);
    close(outfile);
}

int heredoc(char *limiter)
{
    int out;
    out = open("tmp.txt", O_CREAT | O_RDWR | O_TRUNC, 0777);
    heredoc_file(limiter, out);
    return (out);
}