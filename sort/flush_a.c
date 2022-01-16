/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flush_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 04:29:02 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/16 04:30:19 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

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

static unsigned int	count_kept(t_lst *lst)
{
	t_iter			iter;
	t_num			*current;
	unsigned int	kept;

	kept = 0;
	iter_init(&iter, lst, ASC);
	while (iter_next(&iter))
	{
		current = (t_num *)iter.data;
		if (current->keep == TRUE)
			++kept;
	}
	return (kept);
}

static size_t	get_anchor_pos(t_stack *stack)
{
	t_iter			iter;
	t_num			*current;

	iter_init(&iter, stack->a, ASC);
	while (iter_next(&iter))
	{
		current = (t_num *)iter.data;
		if (current->index == stack->anchor_index)
			return (iter.pos);
	}
	return (0);
}

static void	perform_sa_if_needed(t_stack *stack)
{
	unsigned int	kept_with;
	unsigned int	kept_without;

	kept_without = count_kept(stack->a);
	sa(stack);
	stack->anchor_function(stack, get_anchor_pos(stack));
	kept_with = count_kept(stack->a);
	if (kept_with > kept_without)
		ft_putendl_fd("sa", STDOUT_FILENO);
	else
	{
		sa(stack);
		stack->anchor_function(stack, get_anchor_pos(stack));
	}
}

void	flush_a(t_stack *stack)
{
	t_num	*current;

	(void)perform_sa_if_needed;
	while (has_unwanted_numbers(stack->a))
	{
/*		perform_sa_if_needed(stack);
*/		current = data_at(stack->a, 0);
		if (current->keep == FALSE)
			do_op(stack, PB);
		else
			do_op(stack, RA);
	}
}
