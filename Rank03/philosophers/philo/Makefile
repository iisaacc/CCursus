NAME = philo

NAME_BONUS = philo_bonus

LIB = ar rcs

SRC_PARTH = src/

SRCS = ft_aux.c init.c main.c threads.c eat_aux.c check_argv.c one_philo.c

OBJ_NAME = $(SRCS:.c=.o)

OBJ = $(addprefix $(SRC_PARTH), $(OBJ_NAME))

CC = gcc

CFLAGS = -Werror -Wall -Wextra

MYHEADERS = philo.h

RM = rm -f

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -g

all: $(NAME)

$(NAME): $(OBJ) $(MYHEADERS)
	$(CC) $(CFLAGS) -fsanitize=thread -o philo $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS) philo_d

re: fclean all

.PHONY: all clean fclean re
