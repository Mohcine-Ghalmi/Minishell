/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 00:35:58 by selhilal          #+#    #+#             */
/*   Updated: 2023/07/25 22:58:09 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	syntaxerror(t_jointok *token)
{
	t_jointok	*tmp;

	tmp = token;
	if (checksyntax(tmp) == 2 || checksyntax(tmp) == 4)
	{
		printf("syntax error near unexpected token `|'\n");
	}
	if (checksyntax(tmp) == 3)
	{
		printf("syntax error near unexpected token `newline'\n");
	}
}
