/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:38:31 by mghalmi           #+#    #+#             */
/*   Updated: 2023/07/09 13:47:21 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "../Minishell.h"
# include "Pipex/pipex.h"

typedef struct data t_data;

t_data		*struct_args(char *cmd, char *infile, char *outfile, char *append);
int			ft_lstsize(t_data *lst);
int			check_builtins(char *cmd);
void		pipex_test(t_data *cmd, char **env);
void 		execution(t_data *new, char **envp);

#endif