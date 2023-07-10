NAME = libft.a

SRC =  ft_bzero.c ft_calloc.c ft_strdup.c ft_strlen.c ft_strnstr.c ft_split.c ft_putstr.c

OBJ = $(SRC:%.c=%.o)

INCLUDE = libft.HEADER

all = $(NAME)

$(NAME): $(OBJ) 
	ar rc $(NAME) $(OBJ)

%.o:%.c $(INCLUDE)
	$(CC) -c $(CFALGS) $<

clean:
	rm -rvf $(OBJ)

fclean: clean
	rm -rvf $(NAME)

re: fclean all

.PHONY: clean fclean re