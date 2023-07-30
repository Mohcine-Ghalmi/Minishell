/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:40:47 by selhilal          #+#    #+#             */
/*   Updated: 2023/07/18 19:40:47 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# define WORD 1
# define IN	2
# define OUT 3
# define PIPE 4
# define DOBLE_QUDES 5
# define SINGLE_QUDES 6
# define APPEND 7
# define HEC 9
# define SPAE 10

int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		notword(int c);
int		spaces(int c);
char	*ft_substr(char *s, int start, int len);
char	*ft_strdup(char *string);
char	*ft_strjoin(char *s1, char *s2);
int		qudespars(char *str);
size_t	ft_strlen(char *s);

typedef struct env
{
	char		*key;
	char		*value;
	int			option;
	struct env	*next;
}			t_env;

typedef struct token
{
	char			*cmd;
	int				type;

	struct token	*next;
}			t_token;

typedef struct jointok
{
	char			*str;
	int				type;
	struct jointok	*next;
}			t_jointok;

typedef struct lsttoken
{
	char			*str;
	int				type;
	struct lsttoken	*next;
}			t_lsttoken;

typedef struct node
{
	char			**cmd;
	int				fdin;
	int				fdout;
	struct node		*next;

}					t_node;

void	outorappand(char *text, int *i, t_token **token);
void	ft_putstr_fd(char *s, int fd);
void	inorherdoc(char *text, int *i, t_token **token);
void	qudes(char *text, int *i, t_token **token, char **envp);
void	word(char *text, int *i, t_token **token, char **envp);
void	space(char *text, int *i, t_token **token);
char	*dollar(char *text, int *i, char **envp);
void	jointok(t_jointok	**join, t_token *token);
void	ft_back(t_token	**lst, t_token	*new);
void	ft_lstadd_back1(t_jointok	**lst, t_jointok	*new);
void	syntaxerror(t_jointok *token);
char	*out_dollars(char *key, char **env);
int		openfile(char *filename, int mode);
void	addnode_back(t_node	**lst, t_node	*new);
void	free_cmds(char **cmd);
void	free_node(t_node *node);
void	free_lst(t_lsttoken *lst);
void	free_jointoken(t_jointok *token);
void	free_token(t_token *token);
void	*ft_calloc(size_t count, size_t size);

t_token	*ft_lstnew(int type, char *cmd);
t_token	*ft_lstlast(t_token	*lst);

t_node	*create_node(t_lsttoken *token);
t_node	*new_node(char **cmd, int in, int out);
t_node	*last_node(t_node	*lst);

t_jointok	*ft_lstlast1(t_jointok	*lst);
t_jointok	*ft_lstnew1(char *str, int type);
t_lsttoken	*ltoken(t_jointok **token);

#endif