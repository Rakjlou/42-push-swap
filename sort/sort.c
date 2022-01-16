/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 02:03:40 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/16 03:24:12 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ftprintf.h"

static void	align(t_stack *stack)
{
	while (index_at(stack->a, 0) != 0)
		do_op(stack, RA);
}

void	sort(t_stack *stack)
{
	set_kept_nodes(stack);
	flush_a(stack);
	flush_b(stack);
	align(stack);
	/*stack_print(stack);*/
}
