NAME = philo

LIB = ar rcs

SRCS = ft_aux.c init.c main.c threads.c

OBJ_NAME = $(SRCS:.c=.o)

OBJ = $(OBJ_NAME)

CC = gcc

CFLAGS = -Werror -Wall -Wextra

MYHEADERS = philo.h

RM = rm -f

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -g

all: $(NAME)

$(NAME): $(OBJ) $(MYHEADERS)
	$(CC) $(CFLAGS) -o philo $(OBJ)

debug: $(OBJ) $(MYHEADERS)
	$(CC) $(CFLAGS) -o philo_d $(OBJ) -g

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
