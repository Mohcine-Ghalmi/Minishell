/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilise.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:40:56 by selhilal          #+#    #+#             */
/*   Updated: 2023/07/18 19:40:56 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_isalnum(int c)
{
	if ((c >= 48 && c <= 57) || (c >= 97 && c <= 122)
		|| (c >= 65 && c <= 90))
		return (1);
	return (0);
}

int	notword(int c)
{
	if (c == '|' || c == '>' || c == '<' || c == '\'' || c == '\"')
		return (1);
	return (0);
}

int	spaces(int c)
{
	if (c == '\t' || c == ' ')
		return (1);
	return (0);
}
