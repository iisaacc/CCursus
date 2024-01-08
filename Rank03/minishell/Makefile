NAME = minishell

LIB = ar rcs

SRC_PARTH = src/

SRCS = 

OBJ_NAME = $(SRCS:.c=.o)

OBJ = $(addprefix $(SRC_PARTH), $(OBJ_NAME))

CC = gcc

CFLAGS = -Werror -Wall -Wextra

MYHEADERS = minishell.h

RM = rm -f

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -g

all: $(NAME)

$(NAME): $(OBJ) $(MYHEADERS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

debug: $(OBJ) $(MYHEADERS)
	$(CC) -fsanitize=thread $(CFLAGS) -o minishell_d $(OBJ) -g

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS) minishell_d

re: fclean all

.PHONY: all clean fclean re
