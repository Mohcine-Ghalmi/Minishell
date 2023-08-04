/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signel_her.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 14:14:03 by selhilal          #+#    #+#             */
/*   Updated: 2023/08/04 18:36:23 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"
#include "parsing.h"

void	handel(int sig)
{
	(void)sig;
	// exit(1);
    close(0);
}

void signl_herdoc()
{
    rl_catch_signals = 1;
    signal(SIGINT, handel);
    signal(SIGQUIT, SIG_IGN);
}
