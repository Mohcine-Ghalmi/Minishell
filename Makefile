# **************************************************************************** #
#                                                                      #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/09 13:53:40 by mghalmi           #+#    #+#              #
#    Updated: 2023/08/08 06:45:48 by mghalmi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

HEADER = Minishell.h

PARSER_HEADER = parser/parsing.h

HEADER_PIPEX = exec/Pipex/pipex.h

HEADER_LIBFT = libft/libft.h

SRC =   exec/exec_pipes.c \
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
		exec/execution.c \
		libft/ft_bzero.c libft/ft_calloc.c libft/ft_strdup.c libft/ft_strlen.c libft/ft_strnstr.c libft/ft_split.c \
		libft/ft_lstadd_back_env.c libft/ft_lstnew_env.c libft/ft_memmove.c libft/ft_memcpy.c libft/ft_lstlast_env.c libft/ft_substr.c \
		libft/ft_lststzie_env.c libft/ft_lstclear_env.c libft/ft_tolower.c libft/ft_strchr_env.c libft/ft_lstdelone_env.c \
		libft/ft_atoi_shlvl.c libft/ft_itoa_shlvl.c libft/ft_putstr_fd.c \
		exec/Pipex/pipex.c \
		exec/Pipex/pipex_bonus.c \
		exec/Pipex/utils.c \
		exec/Pipex/ft_split.c \
		exec/Pipex/ft_pipex.c \
		exec/Pipex/get_next_line/get_next_line_utils.c \
		exec/Pipex/get_next_line/get_next_line.c \
		exec/Pipex/utils_bonus.c \
		parser.c \
		parser/append.c  parser/ft_free.c parser/jointoken.c       parser/parse.c   parser/rem_spacetoken.c  parser/utilise.c\
		parser/ast_constructor.c        parser/linked_node.c     parser/parsequdes.c        parser/utilise2.c \
		parser/expande.c parser/inoutfile.c       parser/linkedlist.c      parser/qudes.c   parser/token.c   parser/utilise3.c Minishell.c \
		utils.c \
		exec_minishell.c \

OBJ = $(SRC:%.c=%.o)

LDFLAGS="-L/Users/$(USER)/.brew/opt/readline/lib"

CPPFLAGS="-I/Users/$(USER)/.brew/opt/readline/include"


all: $(NAME)

%.o: %.c $(HEADER) $(HEADER_PIPEX) $(HEADER_LIBFT)
	cc -Wall -Wextra -Werror $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(HEADER) $(HEADER_PIPEX) $(HEADER_LIBFT) $(PARSER_HEADER)
	cc -Wall -Wextra -Werror $(CPPFLAGS) $(LDFLAGS) $(OBJ) -lreadline -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
