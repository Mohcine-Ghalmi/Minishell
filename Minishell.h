/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:22:38 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/05 01:52:58 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H


# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>
# include "exec/exec.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libft/libft.h"
# include "parser/parsing.h"
# include <sys/errno.h>
# include <sys/ioctl.h>


typedef struct env
{
	char		*key;
	char		*value;
	int			option;
	struct env	*next;
}		t_env;

typedef struct token	t_token;
typedef struct jointok	t_jointok;
typedef struct lsttoken	t_lsttoken;
typedef struct node		t_node;

int g_test;

void 	show_env_lst(t_env *lst);
void 	show_env_char(char **);
t_env	*envirment(char **old_env);
char	**env_exec(t_env *new_env);
int		pwd_clone(char **cmd, t_env *new_env);
char	*pwd_env(t_env *new_env, int ret);
int		cd_clone(char **cmd, t_env *env);
int		export_clone(char **cmd, t_env *env);
int		first_equale(char *string);
int		option_replace(char *key, t_env *env);
int		unset_clone(t_env *env, char **cmd);
int		echo_clone(char **cmd, t_env *env);
int		find_and_replace(t_env **env, char *key, char *value);
int		find_key(char *key, t_env *env);
char	*add_to_value(t_env *env, char *key, char *value);
char	*shlvl(char *value);
int		exit_clone(t_env *env, char **cmd);
int		olpwd_env(t_env *env);
void	update_status(unsigned int status, t_env *env, int i);
int		first_built(t_node *new, t_env *env);
void	tokena(char *input, t_token **token, char **envp);
void	close_files(int in, int out);
t_node	*inputs(char *input, char **envp);
int		fail_cd(t_env *env, char *oldpwd);
t_env	*main_env(char **old_env, int *i);
void	export_helper(char *cmd, t_env *env, int *ret);

#endif
