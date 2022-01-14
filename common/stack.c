/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 23:36:19 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/14 04:02:10 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "ftprintf.h"

static void	print_num(t_bool print, void *data, int direction)
{
	t_num			*num;
	int				number;
	unsigned int	index;

	num = (t_num *)data;
	if (print)
	{
		index = num->index;
		number = num->num;
	}
	if (print && direction < 0 && num->keep == FALSE)
		ftprintf("\033[30;1m%5u.\033[0m\033[31;1m%12d\033[0m", index, number);
	else if (print && direction < 0)
		ftprintf("\033[30;1m%5u.\033[0m%12d", index, number);
	else if (print && direction > 0)
		ftprintf("\033[30;1m%u.\033[0m %-15d", index, number);
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
	ftprintf("==========================================\n");
	ftprintf("%18s | %-18s\n", "Stack A", "Stack B");
	ftprintf("%18s | %-18s\n", "-------", "-------");
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
	ftprintf("==========================================\n");
}

t_bool	stack_init(t_stack *stack)
{
	stack->a = NULL;
	stack->b = NULL;
	stack->instructions = NULL;
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
	if (stack->instructions != NULL)
		lst_destroy(&stack->instructions, free);
}
