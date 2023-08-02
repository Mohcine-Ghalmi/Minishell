/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:38:31 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/02 10:59:56 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "../Minishell.h"
# include "Pipex/pipex.h"

typedef struct node	t_node;
typedef struct env	t_env;

int			check_builtins(char **cmd, t_env *env);
void		piper(t_node *cmd, t_env *new_env);
void		execution(t_node *new, t_env *envp);
int			show_env(t_env *new_env, char **cmd);
void		free_double(char **str);
void		piper_norm(t_node *cmd, int pipefd[2]);

#endif