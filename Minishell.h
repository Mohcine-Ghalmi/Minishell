/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:22:38 by mghalmi           #+#    #+#             */
/*   Updated: 2023/07/07 14:27:50 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "Pipex/pipex.h"
#include <readline/readline.h>
#include <readline/history.h>
#include "libft/libft.h"

typedef struct data
{
	char *av;
	int infile;
	int outfile;
	int	
	struct data *next;
}       t_data;

char	**environment(char **envp);
t_data	*struct_args(char *cmd, char *infile, char *outfile);
void	pipex_test(t_data *cmd, char **env);
void	execution(t_data *new, char **envp);
int	ft_lstsize(t_data *lst);

#endif
