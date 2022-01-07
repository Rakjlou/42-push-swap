#include "push_swap.h"

void	sa(t_stack *stack)
{
	if (stack->a->size < 2)
		return ;
	lst_swap(stack->a, 0, 1);
}
