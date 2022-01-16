# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 23:54:46 by nsierra-          #+#    #+#              #
#    Updated: 2022/01/16 08:09:16 by nsierra-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# make test v="`ruby -e "puts (-100000..100000).to_a.sample(5).join(' ')"`"
NAME = push_swap

COMMON = common/stack.c \
	common/load.c \
	common/utils.c \
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
	op/ss.c \
	op/utils.c \

SRC = $(COMMON) \
	sort/set_kept_nodes.c \
	sort/find_position.c \
	sort/flush_a.c \
	sort/flush_b.c \
	sort/sort3.c \
	sort/sort5.c \
	sort/sort.c \
	utils.c \
	build_indexes.c \
	main.c \

CHECKER_SRC = $(COMMON) \
	checker.c \

OBJ = $(SRC:.c=.o)
CHECKER_OBJ = $(CHECKER_SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -pedantic -ansi -I libft/ -I inc/
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

test: all checker
	./push_swap $(v) | ./checker $(v)
	./push_swap $(v) | wc -l

testv: all checker
	valgrind ./push_swap $(v) | valgrind ./checker $(v)
	./push_swap $(v) | wc -l

tests:
	@./push_swap $(v) | ./checker $(v)
	@./push_swap $(v) | wc -l

re: fclean all

.PHONY: clean fclean re
