NAME = so_long

LIB = ar rcs

SRC_PARTH = src/

SRCS = so_long.c

LIBFT = ./libft/libft.a

OBJ_NAME = $(SRCS:.c=.o)

OBJ = $(addprefix $(SRC_PARTH), $(OBJ_NAME))

CC = gcc

CFLAGS = -Werror -Wall -Wextra

MYHEADERS = so_long.h \
			./libft/libft.h

RM = rm -f

.c.o:
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

so_long: $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit -o so_long

all: $(NAME)

$(NAME): $(OBJ) $(MYHEADERS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	$(LIB) $(NAME) $(OBJ)

$(LIBFT):
	make -C ./libft all