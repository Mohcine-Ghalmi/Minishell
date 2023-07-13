/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:22:38 by mghalmi           #+#    #+#             */
/*   Updated: 2023/07/13 22:12:13 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "exec/exec.h"
#include <readline/readline.h>
#include <readline/history.h>
#include "libft/libft.h"

typedef struct data
{
	char *av;
	int infile;
	int outfile;
	int append;
	struct data *next;
}		t_data;

typedef struct env
{
	char	*key;
	char	*value;
	struct env *next;
}		t_env;

t_env		*envirment(char **old_env);
t_data		*struct_args(char *cmd, char *infile, char *outfile, char *append);
int			ft_lstsize(t_data *lst);
char		**env_exec(t_env *new_env);
void		for_dollars(char *key, t_env *new_env);

#endif
