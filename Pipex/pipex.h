/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:24:37 by mghalmi           #+#    #+#             */
/*   Updated: 2023/01/26 16:13:32 by mghalmi          ###   ########.fr       */
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
void	exec(char *cmd, char **env);

#endif