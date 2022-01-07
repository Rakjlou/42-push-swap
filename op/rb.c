#include "push_swap.h"

void	rb(t_stack *stack)
{
	if (stack->b->size < 2)
		return ;
	stack->b->first = stack->b->first->next;
}
