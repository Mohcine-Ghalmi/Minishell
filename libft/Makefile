# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/01 18:27:11 by mghalmi           #+#    #+#              #
#    Updated: 2023/08/01 18:27:12 by mghalmi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =  ft_bzero.c ft_calloc.c ft_strdup.c ft_strlen.c ft_strnstr.c ft_split.c ft_putstr.c \
		ft_lstadd_back_env.c ft_lstnew_env.c ft_memmove.c ft_memcpy.c ft_lstlast_env.c ft_substr.c \
		ft_lststzie_env.c ft_lstclear_env.c ft_tolower_str.c ft_tolower.c ft_strchr_env.c ft_lstdelone_env.c \
		ft_atoi_shlvl.c ft_itoa_shlvl.c ft_putstr_fd.c

OBJ = $(SRC:%.c=%.o)

INCLUDE = libft.HEADER

all = $(NAME)

$(NAME): $(OBJ) 
	ar rc $(NAME) $(OBJ)

%.o:%.c $(INCLUDE)
	$(CC) -c $(CFALGS) $<

clean:
	rm -rvf $(OBJ)

fclean: clean
	rm -rvf $(NAME)

re: fclean all

.PHONY: clean fclean re