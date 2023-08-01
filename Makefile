# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/09 13:53:40 by mghalmi           #+#    #+#              #
#    Updated: 2023/08/01 19:17:13 by mghalmi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

HEADER = Minishell.h

PARSER_HEADER = parsing/parsing.h

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
	parser.c \
  	parsing/jointoken.c  parsing/qudes.c  parsing/token.c  parsing/ft_substr.c parsing/linked_node.c parsing/parse.c parsing/ft_free.c  parsing/rem_spacetoken.c \
  	parsing/utilise.c  parsing/utilise2.c \
	parsing/ast_constructor.c parsing/inoutfile.c parsing/linkedlist.c parsing/herdoc.c parsing/parsequdes.c parsing/append.c	parsing/expande.c \
	Minishell.c \

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER) $(HEADER_PIPEX) $(HEADER_LIBFT) $(PARSER_HEADER)
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
