NAME = push_swap
SOURCES = src/push_swap.c src/creat_stack.c src/command.c src/check_error_and_size.c src/sort_2_3.c src/join_the_arg.c src/sort_stack.c src/sort_stack_utelis.c src/algorithm.c
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

r: all clean

.SECONDARY: $(OBJECTS)

.PHONY: all bonus clean fclean re