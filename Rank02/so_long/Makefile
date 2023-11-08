NAME = so_long

LIB = ar rcs

SRC_PARTH = src/

SRCS = so_long.c mapa_check.c

LIBFT = ./libft/libft.a

OBJ_NAME = $(SRCS:.c=.o)

OBJ = $(addprefix $(SRC_PARTH), $(OBJ_NAME))

CC = gcc

CFLAGS = -Werror -Wall -Wextra

MYHEADERS = so_long.h \
			./libft/libft.h

RM = rm -f

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MYHEADERS)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -Lminilibx-linux -lmlx_Linux -lX11 -lXext -o so_long

$(LIBFT):
	make -C ./libft all

clean: libclean
	$(RM) $(OBJ)

libclean:
	make -C ./libft clean

libfclean:
	make -C ./libft fclean

fclean: libfclean clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re libft