/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 23:36:19 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/07 23:37:46 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ftprintf.h"

static void	print_num(t_bool print, void *data, int direction)
{
	if (print && direction < 0)
		ftprintf("%15d", data_to_num(data));
	else if (print && direction > 0)
		ftprintf("%-15d", data_to_num(data));
	else if (direction < 0)
		ftprintf("%15s", "");
	else if (direction > 0)
		ftprintf("%-15s", "");
}

void	stack_print(t_stack *stack)
{
	t_stack_print	ps;

	iter_init(&ps.a, stack->a, ASC);
	iter_init(&ps.b, stack->b, ASC);
	ftprintf("=================================\n");
	ftprintf("%15s | %-15s\n", "Stack A", "Stack B");
	ftprintf("%15s | %-15s\n", "-------", "-------");
	while (42)
	{
		ps.a_print = TRUE;
		ps.b_print = TRUE;
		if (!iter_next(&ps.a))
			ps.a_print = FALSE;
		if (!iter_next(&ps.b))
			ps.b_print = FALSE;
		if (!ps.a_print && !ps.b_print)
			break ;
		print_num(ps.a_print, ps.a.data, -1);
		ftprintf(" | ");
		print_num(ps.b_print, ps.b.data, 1);
		ftprintf("\n");
	}
	ftprintf("=================================\n");
}

t_bool	stack_init(t_stack *stack)
{
	stack->a = lst_new();
	if (stack->a == NULL)
		return (FALSE);
	stack->b = lst_new();
	if (stack->b == NULL)
		return (stack_destroy(stack), FALSE);
	return (TRUE);
}

void	stack_destroy(t_stack *stack)
{
	if (stack->a != NULL)
		lst_destroy(&stack->a, free);
	if (stack->b != NULL)
		lst_destroy(&stack->b, free);
}
