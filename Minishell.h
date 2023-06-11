/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:31:51 by selhilal          #+#    #+#             */
/*   Updated: 2023/06/10 20:57:29 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include<unistd.h>
# include<stdio.h>
# include<unistd.h>
# include<stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct e_lexer
{
	char	pipe;
	char	append[2];
	char	in;
	char	out;
	char	heredoc;
}				t_lexer;

typedef struct e_cmnd
{
	
	
}				t_cmnd;

typedef struct data
{
	char *av;
	int infile;
	int outfile;
	struct data *next;
}		t_cmds;

#endif