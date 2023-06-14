# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 15:18:51 by mghalmi           #+#    #+#              #
#    Updated: 2023/06/13 15:23:36 by mghalmi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

NAMEB = pipex.a

CC = clang

CFLAGS = -Wall -Wextra -Werror 

HEADER = pipex.h

SRC = pipex.c utils.c ft_split.c  ft_pipex.c

SRCB = pipex_bonus.c utils.c ft_split.c ft_pipex.c get_next_line/get_next_line_utils.c get_next_line/get_next_line.c utils_bonus.c

OBJ = $(SRC:c=o)

OBJB = $(SRCB:c=o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

bonus: $(OBJB) $(HEADER)
	$(CC) $(CFLAGS) -o $(NAMEB) $(OBJB)

clean:
	rm -rvf $(OBJ) $(OBJB)

fclean:
	rm -rvf $(OBJ) $(OBJB)
	rm -rvf $(NAME) $(NAMEB)

re: fclean all

.PHONY: clean fclean re bonus