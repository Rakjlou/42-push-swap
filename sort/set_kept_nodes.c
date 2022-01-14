/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_kept_nodes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 03:42:45 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/14 03:58:59 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ftprintf.h"

static unsigned int	set_kept_nodes_by_greater(t_stack *stack, size_t start)
{
	unsigned int	keeping;
	t_node			*node;
	t_num			*current;
	size_t			i;
	int				ref;

	i = 0;
	keeping = 0;
	node = lst_node_at(stack->a, start);
	ref = data_to_num(node->data);
	while (i < stack->a->size)
	{
		current = (t_num *)node->data;
		if (current->num >= ref)
		{
			current->keep = TRUE;
			ref = current->num;
			++keeping;
		}
		else
			current->keep = FALSE;
		node = node->next;
		++i;
	}
	return (keeping);
}

static unsigned int	set_kept_nodes_by_index(t_stack *stack, size_t start)
{
	unsigned int	keeping;
	t_node			*node;
	t_num			*current;
	size_t			i;
	unsigned int	ref;

	i = 0;
	keeping = 0;
	node = lst_node_at(stack->a, start);
	ref = data_to_index(node->data);
	while (i < stack->a->size)
	{
		current = (t_num *)node->data;
		if (current->index == ref || current->index == ref + 1)
		{
			current->keep = TRUE;
			ref = current->index;
			++keeping;
		}
		else
			current->keep = FALSE;
		node = node->next;
		++i;
	}
	return (keeping);
}

static t_bool	better_candidate(
	t_stack *stack,
	unsigned int candidate,
	unsigned int best)
{
	if (candidate > best)
		return (TRUE);
	else if (candidate == best)
	{
		if (index_at(stack->a, candidate) < index_at(stack->a, best))
			return (TRUE);
	}
	return (FALSE);
}

static unsigned int	try_keeping_nodes(
	t_stack *stack,
	size_t *pos,
	unsigned int (*method)(t_stack *, size_t))
{
	size_t			i;
	size_t			best;
	unsigned int	best_keeping;
	unsigned int	candidate;

	i = 0;
	best = 0;
	best_keeping = 0;
	while (i < stack->a->size)
	{
		candidate = method(stack, i);
		if (better_candidate(stack, candidate, best_keeping))
		{
			best = i;
			best_keeping = candidate;
		}
		++i;
	}
	*pos = best;
	return (best_keeping);
}

void	set_kept_nodes(t_stack *stack)
{
	unsigned int	by_greater;
	unsigned int	by_index;
	size_t			pos_by_greater;
	size_t			pos_by_index;

	by_greater = try_keeping_nodes(
			stack,
			&pos_by_greater,
			set_kept_nodes_by_greater);
	by_index = try_keeping_nodes(
			stack,
			&pos_by_index,
			set_kept_nodes_by_index);
	if (by_index >= by_greater)
		set_kept_nodes_by_index(stack, pos_by_index);
	else
		set_kept_nodes_by_greater(stack, pos_by_greater);
	stack_print(stack);
}
