# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdoroana <mdoroana@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 17:02:41 by mdoroana          #+#    #+#              #
#    Updated: 2022/10/28 17:40:13 by mdoroana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_printf.c ft_functions.c
OBJS		= $(SRCS:.c=.o)

CC 			= gcc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror -I.

NAME		= libftprintf.a

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re