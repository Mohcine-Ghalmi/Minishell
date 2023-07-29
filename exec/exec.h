/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:38:31 by mghalmi           #+#    #+#             */
/*   Updated: 2023/07/29 13:11:33 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "../Minishell.h"
# include "Pipex/pipex.h"

typedef struct data t_data;
typedef struct env  t_env;

int			ft_lstsize(t_data *lst);
int         check_builtins(char **cmd, t_env *env);
void	    piper(t_data *cmd, t_env *new_env);
void 		execution(t_data *new, t_env *envp);
int 	    show_env(t_env *new_env, char **cmd);
void        free_double(char    **str);
void        piper_norm(t_data *cmd, int pipefd[2]);

#endif