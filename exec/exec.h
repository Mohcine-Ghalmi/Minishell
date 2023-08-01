/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:38:31 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/01 19:14:55 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "../Minishell.h"
# include "Pipex/pipex.h"

typedef struct node t_node;
typedef struct env  t_env;

int			ft_lstsize(t_node *lst);
int         check_builtins(char **cmd, t_env *env);
void	    piper(t_node *cmd, t_env *new_env);
void 		execution(t_node *new, t_env *envp);
int 	    show_env(t_env *new_env, char **cmd);
void        free_double(char **str);
void        piper_norm(t_node *cmd, int pipefd[2]);

#endif