# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 15:18:51 by mghalmi           #+#    #+#              #
#    Updated: 2023/08/08 08:56:31 by mghalmi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

NAMEB = pipex.a

CC = cc

CFLAGS = -Wall -Wextra -Werror 

HEADER = pipex.h

SRC = pipex.c utils.c ft_split.c  ft_pipex.c

SRCB =
exec/Pipec/pipex.c \
exec/Pipec/pipex_bonus.c \
exec/Pipec/utils.c \
exec/Pipec/ft_split.c \
exec/Pipec/ft_pipex.c \
exec/Pipec/get_next_line/get_next_line_utils.c \
exec/Pipec/get_next_line/get_next_line.c \
exec/Pipec/utils_bonus.c \

OBJ = $(SRC:c=o)

OBJB = $(SRCB:c=o)

%.o: %.c $(HEADER)
	@printf "\033[1;34mCompiling\033[0m $<\r"
	@cc -Wall -Wextra -Werror -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	# $(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus: $(OBJB) $(HEADER)
	ar rc $(NAMEB) $(OBJB)

clean:
	rm -rvf $(OBJ) $(OBJB)

fclean:
	rm -rvf $(OBJ) $(OBJB)
	rm -rvf $(NAME) $(NAMEB)

re: fclean all

.PHONY: clean fclean re bonus