# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/05 18:33:20 by selhilal          #+#    #+#              #
#    Updated: 2023/06/21 18:41:25 by mghalmi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Minishell

SRC = addstruckt.c  ft_strjoin.c  main.c        splite.c      syntaxerror.c

OBJ = $(SRC:%.c=%.o)

all : $(NAME)

$(NAME) : Minishell.h $(OBJ)
	gcc -Wall -Wextra -Werror -lreadline $(OBJ) -o $(NAME)

clean: 
	rm -rfv $(OBJ)

fclean: clean
	rm -rfv $(NAME)

re : fclean  all
