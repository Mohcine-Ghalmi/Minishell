/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 13:31:11 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/20 13:50:15 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

int	check_first(char *cmd)
{
	if ((cmd[0] >= 33 && cmd[0] <= 43) || (cmd[0] > 43 && cmd[0] <= 64)
		|| (cmd[0] >= 91 && cmd[0] <= 94) || cmd[0] == 96
		|| cmd[0] >= 123)
	{
		ft_putstr_fd("minishell: export: `", 2);
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd("` not valid identifier\n", 2);
		return (1);
	}
	return (0);
}
