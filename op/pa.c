#include "push_swap.h"

void	pa(t_stack *stack)
{
	if (stack->b->size < 1)
		return ;
	lst_push_front(stack->a, lst_pop_front(stack->b, NULL));
}
