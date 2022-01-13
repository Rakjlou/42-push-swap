/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 01:04:39 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/13 07:54:39 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ftprintf.h"

static unsigned int	find_position(t_lst *stack, int num)
{
	unsigned int	pos;
	t_iter			iter;

	pos = 0;
	iter_init(&iter, stack, ASC);
	while (iter_next(&iter))
	{
		if (num < data_to_num(iter.data))
			return (pos);
		++pos;
	}
	get_max(stack, &pos);
	return (pos + 1);
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

	build_indexes(stack->a);
	do_op(stack, PB);
	stack_print(stack);
	while (stack->a->size > 3)
		do_op(stack, PB);
	sort3(stack);
	while (stack->b->size > 0)
	{
		position = find_position(stack->a, data_to_num(stack->b->first->data));
		insert_at(stack, position);
	}
	set_min_first(stack);
}
