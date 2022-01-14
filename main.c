/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 23:36:19 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/14 02:09:14 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ftprintf.h"
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

static void	stack_sort(t_stack *stack)
{
	if (stack->a->size == 2 && num_at(stack->a, 0) > num_at(stack->a, 1))
		do_op(stack, SA);
	else if (stack->a->size == 3)
		sort3(stack);
	else if (stack->a->size <= 5)
		sort5(stack);
	else if (stack->a->size > 5)
		sort(stack);
}

int	main(int ac, char **av)
{
	t_stack	stack;

	if (ac <= 1)
		return (EXIT_FAILURE);
	else if (!load(&stack, ac, av))
		return (ft_putendl_fd(ERROR_MSG, STDERR_FILENO), EXIT_FAILURE);
	build_indexes(&stack);
	stack_sort(&stack);
	stack_destroy(&stack);
	return (0);
}
