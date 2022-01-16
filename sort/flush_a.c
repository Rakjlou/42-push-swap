/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flush_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 04:29:02 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/16 03:22:26 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	has_unwanted_numbers(t_lst *stack)
{
	t_iter	iter;
	t_num	*current;

	iter_init(&iter, stack, ASC);
	while (iter_next(&iter))
	{
		current = (t_num *)iter.data;
		if (current->keep == FALSE)
			return (TRUE);
	}
	return (FALSE);
}

void	flush_a(t_stack *stack)
{
	t_num	*current;

	while (has_unwanted_numbers(stack->a))
	{
		current = data_at(stack->a, 0);
		if (current->keep == FALSE)
			do_op(stack, PB);
		else
			do_op(stack, RA);
	}
}
