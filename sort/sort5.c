/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 01:04:39 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/14 01:19:38 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ftprintf.h"
#include <limits.h>

static void	set_first_indexes_aside(t_stack *stack)
{
	size_t			original_size;
	unsigned int	index;

	original_size = stack->a->size;
	while (stack->a->size > 3)
	{
		index = index_at(stack->a, 0);
		if (index == 0 || (original_size > 4 && index == 1))
			do_op(stack, PB);
		else
			do_op(stack, RA);
	}
}

void	sort5(t_stack *stack)
{
	set_first_indexes_aside(stack);
	if (stack->b->size == 2 && index_at(stack->b, 0) < index_at(stack->b, 1))
		do_op(stack, SB);
	sort3(stack);
	while (stack->b->size > 0)
		do_op(stack, PA);
}
