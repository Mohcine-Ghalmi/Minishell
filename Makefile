# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sleeps <sleeps@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/09 13:53:40 by mghalmi           #+#    #+#              #
#    Updated: 2023/07/17 15:49:34 by sleeps           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

HEADER = Minishell.h

HEADER_PIPEX = exec/Pipex/pipex.h

HEADER_LIBFT = libft/libft.h

LIBFT_DIR = libft/

PIPEX_DIR = exec/Pipex/

SRC = exec/exec_pipes.c \
	builtins/environment.c \
	builtins/pwd_clone.c \
	builtins/cd_clone.c \
	builtins/export_clone.c \
	builtins/export_clone_utils.c \
	exec/builtins_check.c \
	builtins/for_dollars.c \
	Minishell.c \

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER) $(HEADER_PIPEX) $(HEADER_LIBFT)
	make -C $(LIBFT_DIR)
	make bonus -C $(PIPEX_DIR)
	make -C $(PIPEX_DIR)
	cc -Wall -Wextra -Werror $(OBJ) -lreadline libft/libft.a exec/Pipex/pipex.a -o $(NAME)

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(PIPEX_DIR)
	rm -rf $(OBJ)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PIPEX_DIR)
	rm -rfv $(NAME)

re: fclean all
