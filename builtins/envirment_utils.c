/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envirment_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:56:27 by mghalmi           #+#    #+#             */
/*   Updated: 2023/07/24 15:29:06 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

char *shlvl(char  *value)
{
    if (ft_atoi_shlvl(value) < 0)
        return (ft_itoa_shlvl(0));
    if(ft_atoi_shlvl(value) == 999)
        return (ft_strdup(""));
    return (ft_itoa_shlvl(ft_atoi_shlvl(value) + 1));
}
