# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/09 13:53:40 by mghalmi           #+#    #+#              #
#    Updated: 2023/08/06 01:42:13 by mghalmi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

HEADER = Minishell.h

PARSER_HEADER = parser/parsing.h

HEADER_PIPEX = exec/Pipex/pipex.h

HEADER_LIBFT = libft/libft.h

LIBFT_DIR = libft/

PIPEX_DIR = exec/Pipex/

SRC = exec/exec_pipes.c \
	builtins/environment.c \
	builtins/envirment_utils.c \
	builtins/pwd_clone.c \
	builtins/cd_clone.c \
	builtins/cd_clone_utils.c \
	builtins/export_clone.c \
	builtins/exit_clone.c \
	builtins/unset_clone.c \
	builtins/export_clone_utils.c \
	builtins/echo_clone.c \
	exec/builtins_check.c \
	parser.c \
	parser/append.c          parser/ft_free.c         parser/jointoken.c       parser/parse.c           parser/rem_spacetoken.c  parser/utilise.c\
	parser/ast_constructor.c        parser/linked_node.c     parser/parsequdes.c        parser/utilise2.c \
	parser/expande.c         parser/inoutfile.c       parser/linkedlist.c      parser/qudes.c           parser/token.c           parser/utilise3.c Minishell.c \
	exec_minishell.c

OBJ = $(SRC:%.c=%.o)

LDFLAGS="-L/Users/$(USER)/.brew/opt/readline/lib"

CPPFLAGS="-I/Users/$(USER)/.brew/opt/readline/include"

all: $(NAME)

$(NAME): $(OBJ) $(HEADER) $(HEADER_PIPEX) $(HEADER_LIBFT) $(PARSER_HEADER) 
	make -C $(LIBFT_DIR)
	make bonus -C $(PIPEX_DIR)
	make -C $(PIPEX_DIR)
	cc -Wall -Wextra -Werror $(CPPFLAGS) $(LDFLAGS) $(OBJ) -lreadline libft/libft.a exec/Pipex/pipex.a -o $(NAME) -g -fsanitize=address

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
