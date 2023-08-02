/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:57:16 by selhilal          #+#    #+#             */
/*   Updated: 2023/08/02 10:21:31 by selhilal         ###   ########.fr       */
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
	while (end && ft_strncmp(end, str, ft_strlen(str))) 
	{
		str = ft_strjoin(str, "\n");
		if (str == NULL)
			return ;
		ft_putstr_fd(str, outfile);
		free(str);
		str = readline("> ");
	}
	free(end);
	free(str);
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
