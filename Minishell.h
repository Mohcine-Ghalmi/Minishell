/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:31:51 by selhilal          #+#    #+#             */
/*   Updated: 2023/06/17 17:01:48 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include<unistd.h>
# include<stdio.h>
# include<unistd.h>
# include<stdlib.h>
# include <stdio.h>
# include<string.h>
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

typedef struct data
{
	char *av;
	int infile;
	int outfile;
	struct data *next;
}		t_data;

void	ft_token(char *str, t_lexer *token);
int		qudes(char *str);
void	parsing_token(char *str, t_lexer *token);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char *s, char c);
#endif