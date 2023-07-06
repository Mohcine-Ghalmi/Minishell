# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/05 18:33:20 by selhilal          #+#    #+#              #
#    Updated: 2023/07/06 17:10:21 by selhilal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Minishell

SRC = linkedlist.c   main.c  utilis.c 

OBJ = $(SRC:%.c=%.o)

all : $(NAME)

$(NAME) : minishell.h $(OBJ)
	gcc -Wall -Wextra -Werror -lreadline $(OBJ) -o $(NAME)

clean: 
	rm -rfv $(OBJ)

fclean: clean
	rm -rfv $(NAME)

re : fclean  all
