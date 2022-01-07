#include "push_swap.h"
#include "ftprintf.h"
#include <unistd.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	t_stack	stack;

	stack.a = NULL;
	stack.b = NULL;
	if (ac <= 1)
		return (EXIT_FAILURE);
	else if (!load(&stack, ac, av))
		return (ft_putendl_fd(ERROR_MSG, STDERR_FILENO), EXIT_FAILURE);
	stack_print(&stack);
	stack_destroy(&stack);
	return (0);
}
