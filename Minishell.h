/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:31:51 by selhilal          #+#    #+#             */
/*   Updated: 2023/07/06 19:59:57 by selhilal         ###   ########.fr       */
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


#define PIPE 0
#define WORD 1
#define IN	2
#define	OUT 3
#define DOLLAR 4
#define DOBLE_DOL 5
#define VAR 6
#define APPEND 7
#define SPACE 8
#define HEC 9

int		notword(int c);
int 	spaces(int c);
char	*ft_substr(char *s, unsigned int start, size_t len);
void	parsing_token(char *str);
int		qudes(char *str);
typedef struct node
{
	char *cmd;
	char *outfile;
	char *infile;
	int expandedfile;
	struct node *next;
}		t_node;

typedef struct token
{
	char		*str;
	int			type;
	struct token *next;
}			t_token;

t_node	*ft_lstnew2(char	*cmd, char *out, char *in);
void	ft_lstadd_back2(t_node	**lst, t_node	*new);
t_token	*ft_lstnew(char	*str, int type);
t_token	*ft_lstlast(t_token	*lst);
void	ft_lstadd_back(t_token	**lst, t_token	*new);

#endif