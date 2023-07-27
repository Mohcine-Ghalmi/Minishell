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

SRC = ast_constructor.c inoutfile.c   linkedlist.c    parsequdes.c	expande.c  jointoken.c   main.c  qudes.c  token.c  ft_substr.c       linked_node.c     parse.c           rem_spacetoken.c  utilise.c

OBJ = $(SRC:%.c=%.o) 

all : $(NAME)

$(NAME) : minishell.h $(OBJ)
	gcc -Wall -Wextra -Werror $(OBJ) -lreadline  -o $(NAME)
clean: 
	rm -rfv $(OBJ)

fclean: clean
	rm -rfv $(NAME)

re : fclean  all