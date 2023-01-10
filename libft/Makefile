NAME		=	libft.a
OBJ_DIR		=	./obj

CC			=	gcc
FLAGS		=	-Wall -Werror -Wextra
COMPILE		=	$(CC) $(FLAGS)

SRC			=	ft_atoi.c \
				ft_bzero.c \
				ft_calloc.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_itoa.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memset.c \
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_split.c \
				ft_strchr.c \
				ft_strdup.c \
				ft_striteri.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strmapi.c \
				ft_strncmp.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strtrim.c \
				ft_substr.c \
				ft_tolower.c \
				ft_toupper.c

BONUS		=	$(SRC) \
				ft_lstnew_bonus.c \
				ft_lstadd_front_bonus.c \
				ft_lstsize_bonus.c \
				ft_lstlast_bonus.c \
				ft_lstadd_back_bonus.c \
				ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c \
				ft_lstiter_bonus.c \
				ft_lstmap_bonus.c

BONUS_OBJ	=	$(addprefix $(OBJ_DIR)/,$(BONUS:.c=.o))
OBJ			=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
HEADER		=	libft.h

all : $(NAME)

$(NAME) : $(OBJ)
	ar -crs $(NAME) $(OBJ)

$(OBJ_DIR)/%.o : %.c $(HEADER) | $(OBJ_DIR)
	$(COMPILE) -c $< -o $@ 

$(OBJ_DIR):
	mkdir -p $@

bonus : $(BONUS_OBJ)
	ar -crs $(NAME) $^

re: fclean all

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(NAME)