NAME	=	cub3d

SRCS	=	./srcs/*.c\
			./srcs/parsing/*.c\
			./lib/gnl/*.c\
			./lib/libasic/*.c

HEADERS	=	./headers/*.h

CC		=	gcc

CFLAGS		=	-Werror -Wextra -Wall

LIX_LIB		=	-lm -lX11 -lXext

LIX_MLX		=	./lib/MLX42/libmlx42.a

OBJ			=	$(SRCS:.c=.o)

.PHONY:		all
all:		$(NAME)

%.o:%.c
			$(CC) -g -c -o $@ $< $c $(CFLAGS)

$(NAME):	$(OBJ) $(HEADER)
			$(CC) -o $(NAME) $(SRCS) $(LIX_MLX) $(LIX_LIB) $(CFLAGS)

.PHONY:		clean
clean:
			$(RM) $(OBJ)

.PHONY:		fclean
fclean:		clean
			$(RM) $(NAME)

.PHONY:		re
re:			fclean all