NAME = push_swap
CC = gcc -Wall -Werror -Wextra -fsanitize=address
HEADER = push_swap.h
SRC =	push_swap.c \
		stack_ops.c \
		sort_algo.c \
		ugly_sort_algo.c \
		error.c \
		stack_ops_rot.c \
		stack_ops_3.c \
		string_option.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(MAKE) -C ./libft
	$(MAKE) -C ./ft_printf
	$(CC) $^ ./libft/libft.a ./ft_printf/libftprintf.a -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) -c $< -o $@

clean :
	rm -f $(OBJ)
	$(MAKE) -C ./libft clean
	$(MAKE) -C ./ft_printf clean

fclean : clean
	rm -f $(NAME)
	$(MAKE) -C ./libft fclean
	$(MAKE) -C ./ft_printf fclean

re :fclean all