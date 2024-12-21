NAME = push_swap
SOURCES = src/push_swap.c src/creat_stack.c
lib = libft/libft.a

OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(lib) $(OBJECTS)
	$(CC) $(OBJECTS) $(lib) -o $(NAME)

$(lib):
	make bonus -C libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all

.SECONDARY: $(OBJECTS)

.PHONY: all bonus clean fclean re