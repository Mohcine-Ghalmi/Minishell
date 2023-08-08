# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/01 18:27:11 by mghalmi           #+#    #+#              #
#    Updated: 2023/08/08 08:55:36 by mghalmi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =  libft/ft_bzero.c libft/ft_calloc.c libft/ft_strdup.c libft/ft_strlen.c libft/ft_strnstr.c libft/ft_split.c libft/ft_putstr.c \
		libft/ft_lstadd_back_env.c libft/ft_lstnew_env.c libft/ft_memmove.c libft/ft_memcpy.c libft/ft_lstlast_env.c libft/ft_substr.c \
		libft/ft_lststzie_env.c libft/ft_lstclear_env.c libft/ft_tolower_str.c libft/ft_tolower.c libft/ft_strchr_env.c libft/ft_lstdelone_env.c \
		libft/ft_atoi_shlvl.c libft/ft_itoa_shlvl.c libft/ft_putstr_fd.c

OBJ = $(SRC:%.c=%.o)

INCLUDE = libft.HEADER

all = $(NAME)

$(NAME): $(OBJ) 
	ar rc $(NAME) $(OBJ)

# %.o:%.c $(INCLUDE)
# 	$(CC) -c $(CFALGS) $<

%.o: %.c $(INCLUDE)
	@printf "\033[1;34mCompiling\033[0m $<\r"
	@cc -Wall -Wextra -Werror -c $< -o $@

clean:
	rm -rvf $(OBJ)

fclean: clean
	rm -rvf $(NAME)

re: fclean all

.PHONY: clean fclean re