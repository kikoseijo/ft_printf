# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jseijo-p <jseijo-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/25 16:13:17 by jseijo-p          #+#    #+#              #
#    Updated: 2022/05/03 12:07:54 by jseijo-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = src/ft_printf.c src/helpers.c

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I. -I libft

RM = /bin/rm -rf

NAME = libftprintf.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
		$(CC) -c $(CFLAGS) $(SRCS) libft/libft.a
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
