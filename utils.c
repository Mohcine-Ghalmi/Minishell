/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 00:46:20 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/07 00:50:41 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

void	two_free(char *end, char *str)
{
	free(end);
	free(str);
}

int	heredoc_file(char *limiter, int outfile, char **envp)
{
	char	*str;
	char	*end;

	if (outfile < 0)
		return (1);
	end = ft_strjoin(limiter, "\n");
	while (1) 
	{
		signal(SIGINT, signl_herdoc);
		str = readline("> ");
		if (!str)
			return (1);
		str = ft_strjoin(str, "\n");
		if (g_test != 3)
			str = her_qudes(str, envp);
		if (!ft_strncmp(end, str, ft_strlen(end)))
			break ;
		ft_putstr_fd(str, outfile);
		free(str);
	}
	two_free(end, str);
	close(outfile);
	if (g_test == -1 || g_test == 4)
		return (1);
	return (0);
}

int	heredocfile(t_lsttoken **token, int in, char **envp)
{
	if (g_test != -1 && g_test != 4)
		in = heredoc((*token)->next->str, envp);
	if ((*token)->next)
		(*token) = (*token)->next;
	return (in);
}