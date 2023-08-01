/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:24:37 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/01 19:24:08 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <err.h>
# include <stdio.h>
# include <string.h>
# include "../../Minishell.h"
# include "get_next_line/get_next_line.h"

char	*path_join(char *path, char *bin);
int		ft_strncmp(char *s1, char *s2, size_t n);
int		ft_strchr1(const char *s, int c);
char	*ft_strdup1(char *str, unsigned int n);
char	**ft_split(char const *s, char c);
void	ft_putstr_fd(char *s, int fd);
void	here_doc(char **av, int infile);
int		ft_strspace(char *str);
void	check_space(char **av, int argc);
void	pipex(char *cmd1, char **env);
void	pipex1(char *cmd1, char *cmd2, char **env);
void	wl(int argc, char **env, char **av, int outfile);
void	exec(char **cmd, char **env);
void	closepipe(int pipefd[2]);
int		openfile_cmd(char *filename, int mode);
void	exec1(char *cmd, char **env);

#endif