NAME = libftprintf.a

LIB = ar rcs

SRC = ft_aux.c ft_printf.c ft_putvar.c ft_putnbr_base_pf.c ft_putptr_pf.c

LIBFT = ./libft/libft.a

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Werror -Wall -Wextra

MYHEADERS = ft_printf.h \
			./libft/libft.h

RM = rm -f

.c.o:
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME): $(OBJ) $(MYHEADERS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	$(LIB) $(NAME) $(OBJ)

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
