/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilise2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 17:01:03 by selhilal          #+#    #+#             */
/*   Updated: 2023/08/05 01:08:45 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

void	sigint_handler(int sig)
{
	(void)sig;
	if (sig == SIGINT && waitpid(-1, NULL, 0) == -1)
	{
		ft_putstr_fd("\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	exit_main(void)
{
	ft_putstr_fd("\033[11C\033[1Aexit\n", 1);
	exit(0);
}
