# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jseijo-p <jseijo-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/25 16:13:17 by jseijo-p          #+#    #+#              #
#    Updated: 2022/05/05 18:15:32 by jseijo-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = src/ft_printf.c src/helpers.c src/ft_print_unint.c src/ft_print_x.c

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = /bin/rm -rf

NAME = libftprintf.a

OBJS = $(SRCS:.c=.o)

all:	$(NAME)

%.o: %.c
		@$(CC) -c $(CFLAGS) $< -I libft -o $(<:.c=.o)

$(NAME):	$(OBJS)
		@make -C libft
		@cp libft/libft.a $(NAME)
		@ar crs $(NAME) $(OBJS)

clean:
		@$(RM) $(OBJS)
		@make -sC ./libft/ clean

fclean:	clean
		@$(RM) $(NAME)

re:	fclean	$(MAKE) $(NAME)

.PHONY: all clean fclean re
