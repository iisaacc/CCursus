NAME = push_swap

BONUS = checker

LIB = ar rcs

SRC_PATH = src/

SRC_BONUS_PATH = bonus_src/

SRCS = do_mvmnt.c do_mvmnt2.c do_mvmnt3.c lst_aux.c main.c movements1.c push_swap.c \
	ft_set_atributes.c sort3.c sort_algorithm.c sort_algorithm2.c error_check.c

BONUS_SRC = do_mvmnt_bonus1.c do_mvmnt_bonus2.c do_mvmnt_bonus3.c lst_aux_bonus.c movements_bonus.c \
	error_check_bonus.c main_bonus.c read_and_do.c push_swap_bonus.c

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

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(MYHEADERS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

debug: $(OBJ) $(MYHEADERS) $(LIBFT)
	$(CC) $(CFLAGS) -o debug $(OBJ) $(LIBFT) -g

bonus: $(BONUS)

$(BONUS): $(OBJ_BONUS) $(BONUSHEADERS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(BONUS) $(OBJ_BONUS) $(LIBFT)

$(LIBFT):
	make -C ./libft all

clean: libclean
	$(RM) $(OBJ) $(OBJ_BONUS)

libclean:
	make -C ./libft clean

libfclean:
	make -C ./libft fclean

fclean: libfclean clean
	$(RM) $(NAME) $(BONUS)

re: fclean all

.PHONY:	all clean fclean re libft