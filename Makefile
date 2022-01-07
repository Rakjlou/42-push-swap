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

COMMON = stack.c \
	load.c \
	utils.c \
	op/pa.c \
	op/pb.c \
	op/ra.c \
	op/rb.c \
	op/rra.c \
	op/rrb.c \
	op/rr.c \
	op/rrr.c \
	op/sa.c \
	op/sb.c \
	op/ss.c

SRC = $(COMMON) \
	main.c

CHECKER_SRC = $(COMMON) \
	main_checker.c

OBJ = $(SRC:.c=.o)
CHECKER_OBJ = $(CHECKER_SRC:.c=.o)

CC = gcc

CFLAGS = -g3 -Wall -Wextra -Werror -pedantic -ansi -I libft/ -I .
LDFLAGS = -L libft/
LDLIBS = -lft

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	$(CC) $(OBJ) -o $@ $(LDFLAGS) $(LDLIBS)

checker: $(CHECKER_OBJ)
	make -C libft/
	$(CC) $(CHECKER_OBJ) -o checker $(LDFLAGS) $(LDLIBS)

clean:
	make -C libft/ clean
	rm -f $(OBJ) $(CHECKER_OBJ)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME) checker

re: fclean all

.PHONY: clean fclean re
