# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junggkim <junggkim@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 15:54:34 by junggkim          #+#    #+#              #
#    Updated: 2022/11/27 19:58:17 by junggkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	= libftprintf.a

SRCS	= ft_printf.c ft_print_conversion.c ft_putstr.c

OBJS	= $(SRCS:%.c=%.o)

FLAGS	= -Wall -Wextra -Werror

CC		= gcc

all		:	$(NAME)

$(NAME)	:	$(OBJS)
	ar	rcs	$(NAME) $(OBJS)

%.o		:	%.c
	$(CC) $(FLAGS) -c -o $@ $^ -I./

clean   :
	rm -f $(OBJS)

fclean  :   clean
	rm -f $(NAME)

re  :   fclean all

.PHONY  :   all clean fclean re
