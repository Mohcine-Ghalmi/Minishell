/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 21:15:34 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/16 23:56:19 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../Minishell.h"

typedef struct node	t_node;
typedef struct env	t_env;

char					*ft_strnstr(const char *htack,
							const char *needle, size_t len);
void					ft_bzero(void *s, size_t n);
char					*ft_strdup(char *s1);
void					*ft_calloc(size_t count, size_t size);
size_t					ft_strlen(const char *s);
char					**ft_split(char *s, char c);
void					ft_putstr_fd(char *s, int fd);
void					ft_lstadd_back_env(t_env **list, t_env *new);
t_env					*ft_lstnew_env(char *key, char *value, int option);
void					*ft_memmove(void *dest, const void *src, size_t len);
void					*ft_memcpy(void *dst, const void *src, size_t n);
t_env					*ft_lstlast_env(t_env *lst);
char					*ft_substr(char *s, unsigned int start, size_t len);
int						ft_lstsize_env(t_env *lst);
void					ft_lstclear_env(t_env **lst);
char					*ft_tolower_str(char *str);
char					*ft_strchr(const char *s, int c);
void					ft_lstclear_struct(t_node **lst);
void					ft_lstdelone(t_env *lst);
char					*ft_itoa_shlvl(long long n);
void					ft_putstr_fd(char *s, int fd);
int						ft_lstsize_node(t_node *lst);
void					ft_lstadd_front_env(t_env **lst, t_env *new);
void					ft_lstadd_front_env(t_env **lst, t_env *new);
long long				ft_atoi_shlvl(char *str);

#endif
