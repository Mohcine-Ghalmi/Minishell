/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:34:37 by selhilal          #+#    #+#             */
/*   Updated: 2023/07/31 16:16:08 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

void	sigint_handler(int sig)
{
	(void)sig;
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("> ", 1);
}

void	exit_main(void)
{
	ft_putstr_fd("\nexit\n", 1);
	exit(0);
}
