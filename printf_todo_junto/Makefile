# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ipizarro <ipizarro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/18 20:49:40 by ipizarro          #+#    #+#              #
#    Updated: 2020/02/18 21:15:34 by ipizarro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC             = new_todo.c
SRC_LIB_PATH    = ./libft/
SRC_LIB_NAME    = ft_strnew.c ft_memset.c ft_iscontained.c ft_strdup.c \
					ft_strlen.c ft_strjoin.c ft_putchar_fd.c ft_strncpy.c \
					ft_rev_str.c ft_atoi.c ft_isspace.c
SRC_LIB         = $(addprefix $(SRC_LIB_PATH), $(SRC_LIB_NAME))
OBJ             = $(SRC:.c=.o)
OBJ_LIB         = $(SRC_LIB:.c=.o)
CFLAGS          = -Wall -Wextra -Werror
#CFLAGS			= -g
CC              = gcc
INCLUDES        = ./
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
