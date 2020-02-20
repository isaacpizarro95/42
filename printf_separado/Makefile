# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ipizarro <ipizarro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/19 19:52:49 by ipizarro          #+#    #+#              #
#    Updated: 2020/02/20 18:10:54 by ipizarro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY = all clean

CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a

SRC = asterisk.c char_conversion.c conversion.c ft_printf.c hexadecimal.c initializer.c \
	int_conversion.c p_conversion.c precision.c utils.c widht.c\

INCLUDE = ft_printf.h

OBJ = $(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $@ $^
	ranlib $(NAME)

%.o:%.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o

fclean:	clean
	rm -f $(NAME)

re:	fclean all
