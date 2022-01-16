/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flush_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 03:23:49 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/16 07:02:57 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ftprintf.h"
#include <limits.h>

static void	flush_best(t_stack *stack, t_flush *flush)
{
	while (flush->rr--)
		do_op(stack, RR);
	while (flush->rb--)
		do_op(stack, RB);
	while (flush->ra--)
		do_op(stack, RA);
	while (flush->rrr--)
		do_op(stack, RRR);
	while (flush->rrb--)
		do_op(stack, RRB);
	while (flush->rra--)
		do_op(stack, RRA);
	if (stack->b->size > 0)
		do_op(stack, PA);
}

static void	flush_init(t_flush *flush, unsigned int apos, unsigned int bpos)
{
	flush->total = 1;
	flush->rr = 0;
	flush->rb = 0;
	flush->ra = 0;
	flush->rrr = 0;
	flush->rrb = 0;
	flush->rra = 0;
	flush->apos = apos;
	flush->bpos = bpos;
}

static void	flush_compute(
	t_stack *stack,
	t_flush *flush,
	unsigned int apos,
	unsigned int bpos)
{
	if (apos <= stack->a->size / 2 && bpos <= stack->b->size / 2)
	{
		flush->rr = ft_min(apos, bpos);
		flush->rb = bpos - flush->rr;
		flush->ra = apos - flush->rr;
	}
	else if (apos > stack->a->size / 2 && bpos > stack->b->size / 2)
	{
		flush->rrr = ft_min(stack->a->size - apos, stack->b->size - bpos);
		flush->rrb = stack->b->size - bpos - flush->rrr;
		flush->rra = stack->a->size - apos - flush->rrr;
	}
	else
	{
		if (bpos <= stack->b->size / 2)
			flush->rb = bpos;
		else
			flush->rrb = stack->b->size - bpos;
		if (apos <= stack->a->size / 2)
			flush->ra = apos;
		else
			flush->rra = stack->a->size - apos;
	}
	flush->total += flush->rr + flush->rb + flush->ra
		+ flush->rrr + flush->rrb + flush->rra;
}

static void	flush_copy(t_flush *src, t_flush *dest)
{
	dest->total = src->total;
	dest->rr = src->rr;
	dest->rb = src->rb;
	dest->ra = src->ra;
	dest->rrr = src->rrr;
	dest->rrb = src->rrb;
	dest->rra = src->rra;
	dest->apos = src->apos;
	dest->bpos = src->bpos;
}

void	flush_b(t_stack *stack)
{
	unsigned int	bpos;
	unsigned int	apos;
	t_flush			best;
	t_flush			current;

	bpos = 0;
	flush_init(&best, 0, 0);
	best.total = UINT_MAX;
	while (bpos < stack->b->size)
	{
		apos = find_position(stack, data_at(stack->b, bpos));
		flush_init(&current, apos, bpos);
		flush_compute(stack, &current, apos, bpos);
		if (current.total < best.total)
			flush_copy(&current, &best);
		++bpos;
	}
	flush_best(stack, &best);
	if (stack->b->size > 0)
		flush_b(stack);
}
