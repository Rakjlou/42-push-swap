/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 02:03:40 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/16 06:42:16 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ftprintf.h"
#include <stdlib.h>

static unsigned int	find_0(t_lst *lst)
{
	t_iter			iter;

	iter_init(&iter, lst, ASC);
	while (iter_next(&iter))
	{
		if (data_to_index(iter.data) == 0)
			return ((unsigned int)iter.pos);
	}
	return (0);
}

static void	align(t_stack *stack)
{
	unsigned int	position;
	unsigned int	i;

	i = 0;
	position = find_0(stack->a);
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
}

void	sort(t_stack *stack)
{
	set_kept_nodes(stack);
	flush_a(stack);
	flush_b(stack);
	align(stack);
}
