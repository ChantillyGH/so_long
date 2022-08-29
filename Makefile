SRCS		= main.c
OBJS		= $(SRCS:.c=.o)

MLX			= mlx_linux/libmlx_Linux.a
CC 			= gcc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror -I.

NAME		= so_long.a

all:		$(NAME)

$(MLX):
	make -C mlx_linux

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME):	$(MLX) $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
			$(RM) $(OBJS)
			make clean -C mlx_linux

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re