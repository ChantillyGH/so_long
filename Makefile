SRCS		= 	srcs/main.c \
				srcs/close_program.c \
				srcs/check_map.c \
				srcs/get_next_line.c \
				srcs/get_next_line_utils.c \
				srcs/key_hooks.c \
				srcs/img_load.c \
				srcs/map_render.c \
				srcs/path_checker.c \

OBJS		= $(subst srcs/, $(PATH_OBJS), $(SRCS:.c=.o))

PATH_OBJS	= objs/

MLX			= mlx_linux/libmlx_Linux.a
LIBFT		= libft/libft.a
FT_PRINTF	= ft_printf/libftprintf.a
CC 			= gcc
RM			= rm -rf
CFLAGS		= -g -Wall -Wextra -Werror -fsanitize=address

NAME		= so_long

all:		$(NAME)

$(MLX):
	make -C mlx_linux

$(LIBFT):
	make -C libft

$(FT_PRINTF):
	make -C ft_printf

$(PATH_OBJS)%.o: srcs/%.c
	mkdir -p $(@D)
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