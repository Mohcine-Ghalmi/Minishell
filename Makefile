# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/18 19:40:39 by selhilal          #+#    #+#              #
#    Updated: 2023/07/18 19:40:39 by selhilal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Minishell

SRC = ast_constructor.c inoutfile.c linkedlist.c herdoc.c ft_putstr_fd.c parsequdes.c append.c	expande.c  jointoken.c   main.c  qudes.c  token.c  ft_substr.c linked_node.c parse.c ft_free.c  rem_spacetoken.c utilise.c  utilise2.c

OBJ = $(SRC:%.c=%.o) 

all : $(NAME)

$(NAME) : Minishell.h $(OBJ)
	gcc -Wall -Wextra -Werror $(OBJ) -lreadline  -o $(NAME) -g -fsanitize=address
clean: 
	rm -rfv $(OBJ)

fclean: clean
	rm -rfv $(NAME)

re : fclean  all