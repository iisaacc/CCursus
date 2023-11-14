NAME = so_long

LIB = ar rcs

SRC_PARTH = src/

SRCS = so_long.c mapa_check.c find_way.c mlx_aux.c assets.c hooks.c movements.c

LIBFT = ./libft/libft.a

PRINTF = ./ft_printf/libftprintf.a

OBJ_NAME = $(SRCS:.c=.o)

OBJ = $(addprefix $(SRC_PARTH), $(OBJ_NAME))

CC = gcc

MACINCLUDES = -I/opt/X11/include -Imlx

MLXFLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit

CFLAGS = -Werror -Wall -Wextra

MYHEADERS = so_long.h \
			./libft/libft.h \
			./ft_printf/ft_printf.h

RM = rm -f

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(MACINCLUDES)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MYHEADERS) $(PRINTF)
	$(CC) $(CFLAGS) -o so_long $(OBJ) $(MLXFLAGS)

linux: $(OBJ) $(LIBFT) $(MYHEADERS) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -Lminilibx-linux -lmlx_Linux -lX11 -lXext -o so_long

debug: $(OBJ) $(LIBFT) $(PRINTF) $(MYHEADERS)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -Lminilibx-linux -lmlx_Linux -lX11 -lXext -o so_longg -g

$(LIBFT):
	make -C ./libft all

$(PRINTF):
	make -C ./ft_printf all

clean: libclean printfclean
	$(RM) $(OBJ)

libclean:
	make -C ./libft clean

libfclean:
	make -C ./libft fclean

printfclean:
	make -C ./ft_printf fclean

fclean: libfclean clean printfclean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re libft