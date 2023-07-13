/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleeps <sleeps@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 21:15:34 by mghalmi           #+#    #+#             */
/*   Updated: 2023/07/13 15:22:58 by sleeps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../Minishell.h"

typedef struct data t_data;
typedef struct env  t_env;

void	ft_bzero(void *s, size_t n);
char	*ft_strdup(const char *s1);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	**ft_split(char const *s, char c);
void	ft_putstr_fd(char *s, int fd);
void	ft_lstadd_back_env(t_env **list, t_env *new);
t_env	*ft_lstnew_env(char *key, char *value);
void	*ft_memmove(void *dest, const void *src, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
t_env	*ft_lstlast(t_env *lst);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int	    ft_lstsize_env(t_env *lst);

#endif
