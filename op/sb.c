#include "push_swap.h"

void	sb(t_stack *stack)
{
	if (stack->b->size < 2)
		return ;
	lst_swap(stack->b, 0, 1);
}
