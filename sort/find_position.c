/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 03:14:37 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/16 03:15:52 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static unsigned int	find_position_of_smallest(t_lst *lst)
{
	t_iter			iter;
	unsigned int	pos;
	unsigned int	smallest;

	smallest = UINT_MAX;
	pos = 0;
	iter_init(&iter, lst, ASC);
	while (iter_next(&iter))
	{
		if (data_to_index(iter.data) < smallest)
		{
			smallest = data_to_index(iter.data);
			pos = (unsigned int)iter.pos;
		}
	}
	return (pos);
}

static unsigned int	find_position_of_greatest(t_lst *lst)
{
	t_iter			iter;
	unsigned int	pos;
	unsigned int	greatest;

	greatest = 0;
	pos = 0;
	iter_init(&iter, lst, ASC);
	while (iter_next(&iter))
	{
		if (data_to_index(iter.data) >= greatest)
		{
			greatest = data_to_index(iter.data);
			pos = (unsigned int)iter.pos + 1;
		}
	}
	return (pos);
}

static int	determine_direction_upwards(t_stack *stack, t_num *num)
{
	t_iter			iter;
	unsigned int	base_index;
	unsigned int	searched;

	base_index = num->index;
	searched = base_index;
	while (searched <= stack->max_index)
	{
		++searched;
		iter_init(&iter, stack->a, ASC);
		while (iter_next(&iter))
		{
			if (data_to_index(iter.data) == searched)
				return ((unsigned int)iter.pos);
		}
	}
	return (find_position_of_greatest(stack->a));
}

static int	determine_direction_downwards(t_stack *stack, t_num *num)
{
	t_iter			iter;
	unsigned int	base_index;
	unsigned int	searched;

	base_index = num->index;
	searched = base_index;
	while (42)
	{
		--searched;
		iter_init(&iter, stack->a, ASC);
		while (iter_next(&iter))
		{
			if (data_to_index(iter.data) == searched)
				return ((unsigned int)iter.pos + 1);
		}
		if (searched == 0)
			break ;
	}
	return (find_position_of_smallest(stack->a));
}

unsigned int	find_position(t_stack *stack, t_num *num)
{
	if (stack->a->size <= 1)
		return (0);
	else if (num->index != stack->max_index)
		return (determine_direction_upwards(stack, num));
	return (determine_direction_downwards(stack, num));
}
