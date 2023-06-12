NAME = libft.a

SRC =  ft_bzero.c ft_calloc.c ft_strdup.c ft_strlen.c

OBJ = $(SRC:%.c=%.o)

INCLUDE = libft.HEADER

all = $(NAME)

$(NAME): $(OBJ) 
	ar rc $(NAME) $(OBJ)

%.o:%.c $(INCLUDE)
	$(CC) -c $(CFALGS) $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re