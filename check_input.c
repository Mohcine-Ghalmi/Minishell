/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 22:40:11 by selhilal          #+#    #+#             */
/*   Updated: 2023/07/12 22:46:22 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

int	parsing(char *text)
{
	if (!parsing_token(text))
		return (0);
	if (!qudes(text))
	{
		printf("syntax error\n");
		return (0);
	}
	return (1);
}
