/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:31:51 by selhilal          #+#    #+#             */
/*   Updated: 2023/07/13 00:29:06 by selhilal         ###   ########.fr       */
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

int		parsing(char *text);
char	*make_spaces(char *tst);
char	*dt_queds(char *str, int *i);
char	*rem_qudes(char *str);
char	*make_spaces(char *tst);
int		ft_strlen(char *str);
int		notword(int c);
int		ft_isalnum(int c);
int		first_syntax(char c);
int		secend_syntax(char *str, int i);
int		last_syntax(char c);
int		ft_strchr(const char *str, int c, int i);
void	strqudes(int *yes, int c);
int		qudes(char *str);
int		secend_syn(char *str, int i);
int		parsing_token(char	*str);
char	*ft_strjoin(char *s1, char *s2);
int		operator(char *str);;
void	my_token(t_token **token, char *text);
t_node	*struct_forM(t_token *token, t_node *node);
t_token	*ft_lstnew(char	*str, int type);
t_token	*ft_lstlast(t_token	*lst);
void	ft_lstadd_back(t_token	**lst, t_token	*new);
t_node	*ft_lstnew2(t_node	*new);
void	ft_lstadd_front(t_node	**lst, t_node	*new);
size_t	ft_strlen1(char *s);
char	*ft_strdup(char *string);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		spaces(int c);
#endif