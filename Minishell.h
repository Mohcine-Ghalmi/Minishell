/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:31:51 by selhilal          #+#    #+#             */
/*   Updated: 2023/07/12 02:56:33 by selhilal         ###   ########.fr       */
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

# define PIPE 0
# define WORD 1
# define IN	2
# define OUT 3
# define DOLLAR 4
# define DOBLE_DOL 5
# define VAR 6
# define APPEND 7
# define DOBLE_QUDES 8
# define SINGLE_QUDES 9
# define HEC 10

int		notword(int c);
int		ft_isalnum(int c);
int		spaces(int c);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		parsing_token(char	*str);
int		qudes(char *str);
int		ft_strchr(const char *str, int c, int i);
int		secend_syntax(char *str, int i);
int		first_syntax(char c);
int		last_syntax(char c);
int		ft_strlen(char *str);
char	*rem_qudes(char *str);
char	*ft_strdup(char *string);
typedef struct node
{
	char		*cmd;
	char		*outfile;
	char		*infile;
	char		*append;
	char		*heredoc;
	struct node	*next;
}		t_node;

typedef struct token
{
	char			*str;
	int				type;
	struct token	*next;
}			t_token;

t_node	*ft_lstnew2(char	*cmd, char *out, char *in, char *append, char *heredoc);
void	ft_lstadd_front(t_node	**lst, t_node	*new);
t_token	*ft_lstnew(char	*str, int type);
t_token	*ft_lstlast(t_token	*lst);
void	ft_lstadd_back(t_token	**lst, t_token	*new);
#endif