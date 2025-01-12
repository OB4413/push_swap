NAME = push_swap
BONUS = checker
SOURCES = src/push_swap.c src/creat_stack.c src/command.c src/command1.c src/check_error_and_size.c src/sort_2_3.c src/join_the_arg.c src/sort_stack.c src/sort_stack_utelis.c src/algorithm.c
SOURCES_BONUS = src_bonus/push_swap_bonus.c src_bonus/creat_stack_bonus.c src_bonus/command_bonus.c src_bonus/command1_bonus.c src_bonus/check_error_and_size_bonus.c src_bonus/join_the_arg_bonus.c src_bonus/get_next_line.c
lib = libft/libft.a

OBJECTS = $(SOURCES:.c=.o)
BOBJECTS = $(SOURCES_BONUS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(lib) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(lib) -o $(NAME)

$(lib):
	make bonus -C libft

bonus: $(lib) $(BOBJECTS)
	$(CC) $(CFLAGS) $(BOBJECTS) $(lib) -o $(BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)
	rm -f $(BOBJECTS)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS)
	make fclean -C libft

re: fclean all

.SECONDARY: $(OBJECTS) $(BOBJECTS)

.PHONY: all bonus clean fclean re
