# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/09 13:53:40 by mghalmi           #+#    #+#              #
#    Updated: 2023/07/25 10:38:28 by mghalmi          ###   ########.fr        #
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
	builtins/envirment_utils.c \
	builtins/pwd_clone.c \
	builtins/cd_clone.c \
	builtins/export_clone.c \
	builtins/exit_clone.c \
	builtins/unset_clone.c \
	builtins/export_clone_utils.c \
	builtins/echo_clone.c \
	exec/builtins_check.c \
	builtins/for_dollars.c \
	Minishell.c \
	# exec/hereDoc.c \

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER) $(HEADER_PIPEX) $(HEADER_LIBFT)
	make -C $(LIBFT_DIR)
	make bonus -C $(PIPEX_DIR)
	make -C $(PIPEX_DIR)
	cc -Wall -Wextra -Werror $(OBJ) -lreadline libft/libft.a exec/Pipex/pipex.a -o $(NAME) #-g -fsanitize=address

# %.o: %.c $(HEADER) $(HEADER_PIPEX) $(HEADER_LIBFT)
# 		cc -Wall -Wextra -Werror -c $< -o $@ -g -fsanitize=address

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(PIPEX_DIR)
	rm -rf $(OBJ)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PIPEX_DIR)
	rm -rfv $(NAME)

re: fclean all
