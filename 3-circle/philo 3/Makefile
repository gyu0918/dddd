# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junggkim <junggkim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/07 15:55:09 by junggkim          #+#    #+#              #
#    Updated: 2023/06/24 15:27:53 by junggkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar

ARFLAGS = -rcs

SRCS = ./init.c \
		./philo.c \
		./start_eating.c \
		./utils.c \
		./utils2.c

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
