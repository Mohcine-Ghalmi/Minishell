/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:57:16 by selhilal          #+#    #+#             */
/*   Updated: 2023/07/31 18:32:02 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

void	heredoc_file(char *limiter, int outfile)
{
	char	*str;
	char	*end;

	if (outfile < 0)
		exit(1);
	end = ft_strjoin(limiter, "\n");
	str = readline(">");
	if (!str)
		exit(1);
	while (limiter && ft_strncmp(limiter, str, ft_strlen(str)))
	{
		ft_putstr_fd(str, outfile);
		free(str);
		str = readline(">");
	}
	free(end);
	close(outfile);
	open("tmp.txt", O_RDONLY);
}

void	heredoc(char *limiter, int infile, int outfile)
{
	int	out;

	out = outfile;
	if (outfile <= 2)
		out = open("tmp.txt", O_CREAT | O_RDWR | O_APPEND, 0777);
	heredoc_file(limiter, out);
	dup2(infile, STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	unlink("tmp.txt");
}
