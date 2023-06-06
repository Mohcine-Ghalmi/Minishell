# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 15:18:51 by mghalmi           #+#    #+#              #
#    Updated: 2023/01/26 16:32:43 by mghalmi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

NAMEB = pipex_bonus

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
	rm -f $(OBJ) $(OBJB)

fclean:
	rm -f $(OBJ) $(OBJB)
	rm -f $(NAME) $(NAMEB) bonus

re: fclean all

.PHONY: clean fclean re bonus