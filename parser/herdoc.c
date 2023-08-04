/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 14:07:52 by selhilal          #+#    #+#             */
/*   Updated: 2023/08/04 18:44:03 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	heredoc_file(char *limiter, int outfile)
{
	char	*str;
	char	*end;
	int		forker;

	if (outfile < 0)
		exit(1);
	forker = fork();
	if (!forker)
	{
		signl_herdoc();
		end = ft_strjoin(limiter, "\n");
		str = readline("> ");
		if (!str)
			exit(1);
		while (end && ft_strncmp(end, str, ft_strlen(end) - 1)) 
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
		exit(0);
	}
	wait(NULL);
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
