# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ipizarro <ipizarro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/19 19:52:49 by ipizarro          #+#    #+#              #
#    Updated: 2020/02/19 19:55:48 by ipizarro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC				=	asterisk.c char_conversion.c conversion.c ft_printf.c hexadecimal.c initializer.c \
					int_conversion.c p_conversion.c precision.c utils.c widht.c \
OBJS             = $(SRC:.c=.o)
CFLAGS          = -Wall -Wextra -Werror
CC              = gcc
INCLUDES        = ft_printf.h
INCLUDES_LIB    = ./libft
NAME            = libftprintf.a

all: $(NAME)
$(NAME):   $(OBJ) $(OBJ_LIB)
	cd $(SRC_LIB_PATH) && $(MAKE)
	ar rc $(NAME) $(OBJ) $(OBJ_LIB)
	ranlib $(NAME)
#	$(CC) $(CFLAGS) -o a.out $(OBJ) libft/libft.a
%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $< -I $(INCLUDES)
%.o: $(SRC_LIB_PATH)/%.c
	$(CC) -c $(CFLAGS) -o $@ $< -I $(INCLUDES_LIB)
clean:
	rm -f *.o
	rm -f $(SRC_LIB_PATH)*.o
fclean: clean
	rm -f $(NAME)
	rm -f $(SRC_LIB_PATH)libft.a
re:         fclean all
.PHONY:     clean fclean
