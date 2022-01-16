/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flush_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 03:23:49 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/16 03:24:41 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	flush_b(t_stack *stack)
{
	unsigned int	position;
	unsigned int	i;

	while (stack->b->size)
	{
		/*stack_print(stack);*/
		position = find_position(stack, data_at(stack->b, 0));
		/*ftprintf("Must be inserted at position %u\n", position);*/
		i = 0;
		if (position <= stack->a->size / 2)
		{
			while (i++ < position)
				do_op(stack, RA);
		}
		else
		{
			while (i++ < stack->a->size - position)
				do_op(stack, RRA);
		}
		do_op(stack, PA);
	}
}
