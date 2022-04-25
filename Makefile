# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jseijo-p <jseijo-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/25 16:13:17 by jseijo-p          #+#    #+#              #
#    Updated: 2022/04/25 16:30:36 by jseijo-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = src/ft_printf.c src/main.c

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I.

RM = /bin/rm -rf

SRCS = libftprintf.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
		$(CC) -c $(CFLAGS) $(SRCS)
		ar crs $(OBJS) -o $(NAME)

clean:
		$(RM) $(OBJS)

fclean:
		clean
		$(RM) $(NAME)

re:
		fclean
		$(NAME)

.PHONY: all clean fclean re
