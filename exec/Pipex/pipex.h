/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleeps <sleeps@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:24:37 by mghalmi           #+#    #+#             */
/*   Updated: 2023/07/17 02:03:14 by sleeps           ###   ########.fr       */
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
int		ft_strncmp(const char *s1, const char *s2, size_t n);
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
int		openfile(char *filename, int mode);
void	exec1(char *cmd, char **env);

#endif