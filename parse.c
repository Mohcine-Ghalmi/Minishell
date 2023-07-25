/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 00:35:58 by selhilal          #+#    #+#             */
/*   Updated: 2023/07/25 16:51:35 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	syntaxerror(t_jointok *token)
{
	if (checksyntax(token) == 2 || checksyntax(token) == 4)
	{
		printf("syntax error near unexpected token `|'\n");
	}
	if (checksyntax(token) == 3)
	{
		printf("syntax error near unexpected token `newline'\n");
	}
}
