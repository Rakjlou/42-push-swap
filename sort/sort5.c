/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 01:04:39 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/13 10:05:12 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ftprintf.h"
#include <limits.h>

static unsigned int	find_position(t_stack *stack, t_num *to_insert)
{
	unsigned int	candidate;
	t_iter			iter;
	int				dir;

	dir = 1;
	if (to_insert->index == stack->max_index)
		dir = -1;
	candidate = to_insert->index;
	while (42)
	{
		candidate += dir;
		iter_init(&iter, stack->a, ASC);
		while (iter_next(&iter))
		{
			if (data_to_index(iter.data) == candidate)
			{
				if (dir == -1)
					return ((unsigned int)iter.pos + 1);
				return ((unsigned int)iter.pos);
			}
		}
		if ((dir == -1 && candidate == 0) || (dir == 1 && candidate >= stack->max_index))
			break ;
	}
	return (0);
}

static void	insert_at(t_stack *stack, unsigned int pos)
{
	if (pos == 0)
		do_op(stack, PA);
	else if (pos == 1)
		do_2op(stack, PA, SA);
	else if (pos == 2 && stack->a->size == 3)
		do_2op(stack, RRA, PA);
	else if (pos == 2 && stack->a->size == 4)
		do_3op(stack, RRA, RRA, PA);
	else if (pos == 3 && stack->a->size == 3)
		do_op(stack, PA);
	else if (pos == 3 && stack->a->size == 4)
		do_2op(stack, RRA, PA);
	else
	{
		do_op(stack, PA);
	}
}

static void	set_min_first(t_stack *stack)
{
	unsigned int	min_pos;
	unsigned int	i;

	get_min(stack->a, &min_pos);
	i = 0;
	if (min_pos <= stack->a->size / 2)
	{
		while (i++ < min_pos)
			do_op(stack, RA);
	}
	else
	{
		while (i++ < stack->a->size - min_pos)
			do_op(stack, RRA);
	}
}

void	sort5(t_stack *stack)
{
	unsigned int	position;

	while (stack->a->size > 3)
		do_op(stack, PB);
	sort3(stack);
	while (stack->b->size > 0)
	{
		stack_print(stack);
		position = find_position(stack, data_at(stack->b, 0));
		insert_at(stack, position);
	}
	stack_print(stack);
	set_min_first(stack);
	ft_putendl_fd("Ended", 1);
	stack_print(stack);
}
