NAME = pipex

LIB = @ar rcs

SRC_PARTH = src/

SRCS = pipex.c parse_args.c init_clean.c ft_split_mod.c ft_clean_cmnd.c

LIBFT = ./libft/libft.a

PRINTF = ./ft_printf/libftprintf.a

OBJ_NAME = $(SRCS:.c=.o)

OBJ = $(addprefix $(SRC_PARTH), $(OBJ_NAME))

CC = gcc

CFLAGS = -Werror -Wall -Wextra

MYHEADERS = pipex.h \
			./libft/libft.h \
			./ft_printf/ft_printf.h

RM = rm -f

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -g

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MYHEADERS) $(PRINTF)
	$(CC) $(CFLAGS) -o pipex $(OBJ) $(PRINTF) $(LIBFT)

debug: $(OBJ) $(LIBFT) $(MYHEADERS) $(PRINTF)
	$(CC) -o pipexd $(OBJ) $(PRINTF) $(LIBFT) -g

$(LIBFT):
	@make -C ./libft all

$(PRINTF):
	@make -C ./ft_printf all

clean: libclean printfclean
	$(RM) $(OBJ)

libclean:
	@make -C ./libft clean

libfclean:
	@make -C ./libft fclean

printfclean:
	@make -C ./ft_printf fclean

fclean: libfclean clean printfclean
	@$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re libft