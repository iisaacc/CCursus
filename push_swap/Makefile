NAME = push_swap

LIB = ar rcs

SRC_PATH = src/

SRC_BONUS_PATH = bonus_src/

SRCS = do_mvmnt.c lst_aux.c main.c movements1.c push_swap.c \
	ft_set_atributes.c sort3.c sort_algorithm.c error_check.c

BONUS_SRC = do_mvmnt_bonus.c lst_aux_bonus.c movements_bonus.c push_swap_bonus.c \
	error_check_bonus.c main_bonus.c

LIBFT = ./libft/libft.a

OBJ_NAME = $(SRCS:.c=.o)

OBJ_BONUS_NAME = $(BONUS_SRC:.c=.o)

OBJ = $(addprefix $(SRC_PATH), $(OBJ_NAME))

OBJ_BONUS = $(addprefix $(SRC_BONUS_PATH), $(OBJ_BONUS_NAME))

CC = gcc

CFLAGS = -Werror -Wall -Wextra

MYHEADERS = push_swap.h \
			./libft/libft.h

BONUSHEADERS = push_swap_bonus.h \
				./libft/libft.h

RM = rm -f

.c.o:
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

push_swap: $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

all: $(NAME)

$(NAME): $(OBJ) $(MYHEADERS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	$(LIB) $(NAME) $(OBJ)

$(LIBFT):
	make -C ./libft all

clean: libclean
	$(RM) $(OBJ) $(OBJ_BONUS)

libclean:
	make -C ./libft clean

libfclean:
	make -C ./libft fclean

fclean: libfclean clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re libft