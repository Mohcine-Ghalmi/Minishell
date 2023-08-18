/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 01:10:42 by selhilal          #+#    #+#             */
/*   Updated: 2023/08/18 11:15:14 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"
#include "exec.h"

void	ms(int status)
{
	char	*str;

	str = ft_itoa_shlvl(status);
	ft_putstr_fd("Segmentation fault: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	free(str);
}

void	status_seg(int status, t_env *envp)
{
	if (WTERMSIG(status) == 2)
	{
		ft_putstr_fd("\n", 1);
		update_status(128 + WTERMSIG(status), envp, 1);
	}
	else if (WTERMSIG(status) == 3)
	{
		ft_putstr_fd("Quit: 3\n", 1);
		update_status(128 + WTERMSIG(status), envp, 1);
	}
	if (WTERMSIG(status) == 11)
	{
		ms(WTERMSIG(status));
		update_status(128 + WTERMSIG(status), envp, 1);
	}
}

void	update_and_wait(int ifcond, t_env *envp, pid_t	pid)
{
	int  last;

	last = 0;
	waitpid(pid, &last, 0);
	while (wait(NULL) != -1)
		;
	if (WTERMSIG(last))
		status_seg(last, envp);
	else if (WEXITSTATUS(last) > 0)
	{
		if (WEXITSTATUS(last) == 141)
			update_status(126, envp, 1);
		else
			update_status(WEXITSTATUS(last), envp, 1);
	}
	else if (ifcond < 2)
		update_status(ifcond, envp, 1);
}

void	close_all_fd(void)
{
	int			i;
	struct stat	fd_stat;

	i = 3;
	while (fstat(i, &fd_stat) == 0 || i < 256)
	{
		close(i);
		i++;
	}
}
