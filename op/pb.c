#include "push_swap.h"

void	pb(t_stack *stack)
{
	if (stack->a->size < 1)
		return ;
	lst_push_front(stack->b, lst_pop_front(stack->a, NULL));
}
