CC 			=	cc
CFLAGS		=	-Wall -Wextra -Werror
NAME		= 	fractal

SRC			=	fractal.c extras.c complex.c hooksundso.c inputundso.c
OBJ			=	$(SRC:.c=.o)

FTPRINTF_PATH	=	./printf/
FTPRINTF	=	$(FTPRINTF_PATH)/libftprintf.a
LIBFT_PATH	=	./printf/libft/
LIBFT		= 	libft.a

all:		 $(FTPRINTF) $(NAME)

$(FTPRINTF):
				cd $(FTPRINTF_PATH) && $(MAKE)

$(NAME):	$(OBJ) $(FTPRINTF)
		$(CC) $(OBJ) -Lprintf -lftprintf -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
				cd $(FTPRINTF_PATH) && $(MAKE) clean
				rm -f $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

fclean: clean
				make -C $(FTPRINTF_PATH) fclean
				rm -f $(NAME) 

re: 			fclean all

.PHONY:		all clean fclean re bonus libft