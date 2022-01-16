/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flush_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 03:23:49 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/16 04:46:49 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ftprintf.h"
#include <limits.h>
#include <stdlib.h>

static void	flush_best(t_stack *stack, unsigned int nth)
{
	unsigned int	position;
	unsigned int	i;

/*	stack_print(stack);
*/	i = 0;
	position = find_position(stack, data_at(stack->b, nth));
	if (position <= stack->a->size / 2)
	{
		while (nth && i < position)
			(++i, --nth, do_op(stack, RR));
		while (nth--)
			do_op(stack, RB);
		while (i++ < position)
			do_op(stack, RA);
	}
	else
	{
		while (nth--)
			do_op(stack, RB);
		while (i++ < stack->a->size - position)
			do_op(stack, RRA);
	}
	do_op(stack, PA);
/*	stack_print(stack);
*/}

void	flush_b(t_stack *stack)
{
	unsigned int	best_to_insert;
	unsigned int	best_to_insert_actions;
	unsigned int	actions;
	unsigned int	position;
	unsigned int	i;

	i = 0;
	best_to_insert = 0;
	best_to_insert_actions = UINT_MAX;
	while (i < stack->b->size)
	{
		actions = 0;
		position = find_position(stack, data_at(stack->b, i));
		if (position <= stack->a->size / 2)
			actions += position + i;
		else
			actions += (stack->a->size - position) + i;
		if (actions < best_to_insert_actions)
		{
			best_to_insert = i;
			best_to_insert_actions = actions;
		}
		++i;
	}
/*	ftprintf("Best to flush is at pos %u with %u actions\n", best_to_insert, best_to_insert_actions);
*/	flush_best(stack, best_to_insert);
	if (stack->b->size > 0)
		flush_b(stack);
}
