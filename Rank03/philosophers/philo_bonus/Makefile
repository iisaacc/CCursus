NAME = philo_bonus

LIB = ar rcs

SRC_BONUS = src_bonus/

SRCS_BONUS = main_bonus.c check_argv_bonus.c init_bonus.c \
			routine_bonus.c ft_aux_bonus.c one_philo_bonus.c \

OBJ_NAME_BONUS = $(SRCS_BONUS:.c=.o)

OBJ_BONUS = $(addprefix $(SRC_BONUS), $(OBJ_NAME_BONUS))

CC = gcc

CFLAGS = -Werror -Wall -Wextra

MYHEADERS_BONUS = philo_bonus.h

RM = rm -f

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -g

all: $(NAME)

$(NAME): $(OBJ_BONUS) $(MYHEADERS_BONUS)
	$(CC) $(CFLAGS) -o philo_bonus $(OBJ_BONUS)

clean:
	$(RM) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME) philo_d philo_d_bonus

re: fclean all

.PHONY: all clean fclean re
