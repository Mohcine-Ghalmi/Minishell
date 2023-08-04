/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 14:07:52 by selhilal          #+#    #+#             */
/*   Updated: 2023/08/04 21:03:28 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "../Minishell.h"

// void signl_herdoc()
// {
//     ioctl(0, TIOCSTI, "\4");
//     g_test = -1;
// }


// int	heredoc_file(char *limiter, int outfile)
// {
// 	char	*str;
// 	char	*end;

// 	if (outfile < 0)
// 		return (1);
// 	signal(SIGINT, signl_herdoc);
// 	end = ft_strjoin(limiter, "\n");
// 	str = readline("> ");
// 	if (!str)
// 		return (1);
// 	while (end && ft_strncmp(end, str, ft_strlen(end) - 1)) 
// 	{
// 		str = ft_strjoin(str, "\n");
// 		if (str == NULL)
// 			return (1);
// 		ft_putstr_fd(str, outfile);
// 		free(str);
// 		str = readline("> ");
// 	}
// 	free(end);
// 	free(str);
// 	close(outfile);
// 	if (g_test == -1)
// 		return(1);
// 	return(0);
// }

// int	heredoc(char *limiter)
// {
// 	int	fd[2];

// 	pipe(fd);
// 	g_test = 0;
// 	if (fd < 0)
// 		return (0);
// 	if(heredoc_file(limiter, fd[1]))
// 		return(1);
// 	return (fd[0]);
// }
