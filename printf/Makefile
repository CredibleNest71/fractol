CC 			=	cc
CFLAGS		=	-Wall -Wextra -Werror
NAME		=	libftprintf.a
SRC			=	ft_printf.c launch_print.c print_hex.c print_num.c
OBJ			=	$(SRC:.c=.o)
LIBFT_PATH	=	./libft/
LIBFT		= 	libft.a

all:		$(NAME)

.c.o:
			${CC} ${CFLAGS} -c  -I${LIBFT_PATH} $< -o ${<:.c=.o}


$(NAME):	$(OBJ)
				cd $(LIBFT_PATH) && $(MAKE) && cp -v ${LIBFT} ../${NAME}
				ar -crs $(NAME) $(OBJ)

clean:
				cd libft && $(MAKE) clean
				rm -f $(OBJ)

fclean: clean
				make -C $(LIBFT_PATH) fclean
				rm -f $(NAME) $(LIBFT)

re: 			fclean all

.PHONY:		all clean fclean re bonus libft