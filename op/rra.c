#include "push_swap.h"

void	rra(t_stack *stack)
{
	if (stack->a->size < 2)
		return ;
	stack->a->first = stack->a->first->prev;
}
