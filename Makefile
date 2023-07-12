# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/05 18:33:20 by selhilal          #+#    #+#              #
#    Updated: 2023/07/12 23:05:51 by selhilal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Minishell

SRC = check_input.c creat_node.c creat_token.c ft_strjoin.c ft_substr.c linkedlist.c main.c qudes.c syntaxerror.c syntaxerror2.c token_operator.c utilis.c

OBJ = $(SRC:%.c=%.o)

all : $(NAME)

$(NAME) : minishell.h $(OBJ)
	gcc -Wall -Wextra -Werror -lreadline $(OBJ) -o $(NAME)

clean: 
	rm -rfv $(OBJ)

fclean: clean
	rm -rfv $(NAME)

re : fclean  all
