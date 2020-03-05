# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ipizarro <ipizarro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/19 19:52:49 by ipizarro          #+#    #+#              #
#    Updated: 2020/03/05 19:12:07 by ipizarro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY = all clean

CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a

SRC = asterisk.c char_conversion.c conversion.c ft_printf.c hexadecimal.c initializer.c \
	width.c int_conversion.c precision.c utils.c ft_atoi.c ft_substr.c \
	ft_isalpha.c ft_iscontained.c ft_isdigit.c ft_putchar.c ft_putstr.c ft_strlen.c  \
	ft_isspace.c ft_itoa.c ft_calloc.c ft_memset.c ft_nbrlen.c ft_strdup.c ft_unsigned_itoa.c \

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
