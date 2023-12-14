NAME = philo

NAME_BONUS = philo_bonus

LIB = ar rcs

SRC_PARTH = src/

SRC_BONUS = src_bonus/

SRCS = ft_aux.c init.c main.c threads.c eat_aux.c

SRCS_BONUS = main_bonus.c

OBJ_NAME = $(SRCS:.c=.o)

OBJ_NAME_BONUS = $(SRCS_BONUS:.c=.o)

OBJ = $(addprefix $(SRC_PARTH), $(OBJ_NAME))

OBJ_BONUS = $(addprefix $(SRC_BONUS), $(OBJ_NAME_BONUS))

CC = gcc

CFLAGS = -Werror -Wall -Wextra

MYHEADERS = philo.h

MYHEADERS_BONUS = philo_bonus.h

RM = rm -f

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -g

all: $(NAME)

$(NAME): $(OBJ) $(MYHEADERS)
	$(CC) $(CFLAGS) -o philo $(OBJ)

bonus: $(OBJ_BONUS) $(MYHEADERS_BONUS)
	$(CC) $(CFLAGS) -o philo_bonus $(OBJ_BONUS)

debug: $(OBJ) $(MYHEADERS)
	$(CC) -fsanitize=thread $(CFLAGS) -o philo_d $(OBJ) -g

debug_bonus: $(OBJ_BONUS) $(MYHEADERS_BONUS)
	$(CC) -fsanitize=thread $(CFLAGS) -o philo_d_bonus $(OBJ_BONUS) -g

clean:
	$(RM) $(OBJ)

bonus_clean:
	$(RM) $(OBJ_BONUS)

fclean: clean bonus_clean
	$(RM) $(NAME) $(NAME_BONUS) philo_d philo_d_bonus

re: fclean all

.PHONY: all clean fclean re
