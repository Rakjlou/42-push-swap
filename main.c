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
	else
		ft_putendl_fd("TOO BIG FOR NOW", STDOUT_FILENO);
}

int	main(int ac, char **av)
{
	t_stack	stack;

	stack.a = NULL;
	stack.b = NULL;
	if (ac <= 1)
		return (EXIT_FAILURE);
	else if (!load(&stack, ac, av))
		return (ft_putendl_fd(ERROR_MSG, STDERR_FILENO), EXIT_FAILURE);
	stack_sort(&stack);
	stack_destroy(&stack);
	return (0);
}
