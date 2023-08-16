/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 00:26:22 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/17 00:31:20 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	for_seg(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

void	clone_std(int in, int out)
{
	dup2(in, STDIN_FILENO);
	dup2(out, STDOUT_FILENO);
}
