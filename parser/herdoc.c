/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:57:16 by selhilal          #+#    #+#             */
/*   Updated: 2023/08/01 18:20:14 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	heredoc_file(char *limiter, int outfile)
{
	char	*str;
	char	*end;

	if (outfile < 0)
		exit(1);
	end = ft_strjoin(limiter, "\n");
	str = readline("> ");
	if (!str)
		exit(1);
	while (limiter && ft_strncmp(limiter, str, ft_strlen(str))) 
	{
		str = ft_strjoin(str, "\n");
		ft_putstr_fd(str, outfile);
		free(str);
		str = readline("> ");
	}
	free(end);
	close(outfile);
}

int	heredoc(char *limiter)
{
	int	fd[2];

	pipe(fd);
	if (fd < 0)
		return (0);
	heredoc_file(limiter, fd[1]);
	return (fd[0]);
}
