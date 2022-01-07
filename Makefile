# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 23:54:46 by nsierra-          #+#    #+#              #
#    Updated: 2021/12/12 08:30:38 by nsierra-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = main.c \
	stack.c \
	load.c \
	utils.c

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -g3 -Wall -Wextra -Werror -pedantic -ansi -I libft/
LDFLAGS = -L libft/
LDLIBS = -lft

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	$(CC) $(OBJ) -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	make -C libft/ clean
	rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
