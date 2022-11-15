SRCS		= main.c close_program.c check_map.c get_next_line.c get_next_line_utils.c key_hooks.c \
				img_load.c map_render.c path_checker.c
OBJS		= $(SRCS:.c=.o)

MLX			= mlx_linux/libmlx_Linux.a
LIBFT		= libft/libft.a
FT_PRINTF	= ft_printf/libftprintf.a
CC 			= gcc
RM			= rm -rf
CFLAGS		= -g -fsanitize=address

NAME		= so_long

all:		$(NAME)

$(MLX):
	make -C mlx_linux

$(LIBFT):
	make -C libft

$(FT_PRINTF):
	make -C ft_printf

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME):	$(MLX) $(LIBFT) $(FT_PRINTF) $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -Llibft -lft -Lft_printf -lftprintf -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
			$(RM) $(OBJS)
			make clean -C mlx_linux
			make clean -C libft
			make clean -C ft_printf

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re