NAME = Minishell

HEADER = Minishell.h
HEADER_PIPEX = Pipex/pipex.h

all: $(NAME)

$(NAME): $(HEADER) $(HEADER_PIPEX)
	gcc test.c Pipex/ft_pipex.c Pipex/ft_split.c Pipex/pipex.c Pipex/utils.c -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	re -rfv $(NAME)

re: fclean all