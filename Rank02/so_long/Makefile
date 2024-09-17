NAME = so_long

NAME_BONUS = so_long_bonus

LIB = ar rcs

SRC_PARTH = src/

SRC_BONUS = src_bonus/

SRCS = so_long.c mapa_check.c find_way.c mlx_aux.c assets.c hooks.c movements.c

SRCS_BONUS = so_long_bonus.c mapa_check_bonus.c find_way_bonus.c mlx_aux_bonus.c \
				assets_bonus.c hooks_bonus.c movements_bonus.c

LIBFT = ./libft/libft.a

PRINTF = ./ft_printf/libftprintf.a

MINILIBX = ./minilibx/libmlx.a

OBJ_NAME = $(SRCS:.c=.o)

OBJ_NAME_BONUS = $(SRCS_BONUS:.c=.o)

OBJ = $(addprefix $(SRC_PARTH), $(OBJ_NAME))

OBJ_BONUS = $(addprefix $(SRC_BONUS), $(OBJ_NAME_BONUS))

CC = gcc

CFLAGS = -Wall -Wextra -Werror -Iinclude/

MLXFLAGS = -Lminilibx -lmlx -framework OpenGL -framework AppKit

MYHEADERS = so_long.h \
			./libft/libft.h \
			./ft_printf/ft_printf.h \
			./minilibx/mlx.h

MYHEADERS_BONUS = so_long_bonus.h \
			./libft/libft.h \
			./ft_printf/ft_printf.h \
			./minilibx/mlx.h

RM = rm -f

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -g

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MYHEADERS) $(PRINTF) $(MINILIBX)
	$(CC) $(CFLAGS) -o so_long $(OBJ) $(MINILIBX) $(MLXFLAGS) $(LIBFT) $(PRINTF)

bonus: $(OBJ_BONUS) $(LIBFT) $(MYHEADERS_BONUS) $(PRINTF) $(MINILIBX)
	$(CC) $(CFLAGS) -o so_long_bonus $(OBJ_BONUS) $(MINILIBX) $(MLXFLAGS) $(LIBFT) $(PRINTF)

linux: $(OBJ) $(LIBFT) $(MYHEADERS) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -Lminilibx-linux -lmlx_Linux -lX11 -lXext -o so_long

debug: $(OBJ) $(LIBFT) $(MYHEADERS) $(PRINTF) $(MINILIBX)
	$(CC) $(CFLAGS) -o so_longd -g $(OBJ) $(MINILIBX) $(MLXFLAGS) $(LIBFT) $(PRINTF)

$(LIBFT):
	make -C ./libft all

$(PRINTF):
	make -C ./ft_printf all

$(MINILIBX):
	make -C ./minilibx all

clean: libclean printfclean minilibxclean bonusclean
	$(RM) $(OBJ)

bonusclean: libclean printfclean minilibxclean
	$(RM) $(OBJ_BONUS)

minilibxclean:
	make -C ./minilibx clean

libclean:
	make -C ./libft clean

libfclean:
	make -C ./libft fclean

printfclean:
	make -C ./ft_printf fclean

fclean: libfclean clean printfclean minilibxclean bonusclean
	$(RM) $(NAME) $(NAME_BONUS) so_longd

re: fclean all

.PHONY:	all clean fclean re libft