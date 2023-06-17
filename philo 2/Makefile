# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junggkim <junggkim@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/07 15:55:09 by junggkim          #+#    #+#              #
#    Updated: 2023/06/07 15:55:11 by junggkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=thread

AR = ar

ARFLAGS = -rcs

SRCS = ./init.c \
		./philo.c \
		./start_eating.c \
		./utils.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) :	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -I./ -o $@

clean :
	rm -rf	$(OBJS)

fclean :	clean
	rm -rf	$(NAME)

re	:
	$(MAKE)	fclean
	$(MAKE)	all

.PHONY : all clean fclean re bonus
