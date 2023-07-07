NAME = Minishell

HEADER = Minishell.h

HEADER_PIPEX = Pipex/pipex.h

HEADER_LIBFT = libft/libft.h

LIBFT_DIR = libft/

PIPEX_DIR = Pipex/

SRC = exec/exec.c exec/environment.c random_test.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER) $(HEADER_PIPEX) $(HEADER_LIBFT)
	make -C $(LIBFT_DIR)
	make bonus -C $(PIPEX_DIR)
	make -C $(PIPEX_DIR)
	cc -Wall -Wextra -Werror $(OBJ) -lreadline libft/libft.a Pipex/pipex.a -o $(NAME)

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(PIPEX_DIR)
	rm -rf $(OBJ)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PIPEX_DIR)
	rm -rfv $(NAME)

re: fclean all
