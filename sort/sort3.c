#include "push_swap.h"

static void	get_min_max_mid(t_stack *stack, int *min, int *max, int *mid)
{
	int	i;
	int	candidate;

	*max = get_max(stack->a, NULL);
	*min = get_min(stack->a, NULL);
	i = 0;
	while (i < 3)
	{
		candidate = num_at(stack->a, i);
		if (candidate != *max && candidate != *min)
		{
			*mid = candidate;
			return ;
		}
		++i;
	}
}

static int	get_pos(t_lst *stack, int num)
{
	t_iter	iter;
	int		candidate;

	iter_init(&iter, stack, ASC);
	while (iter_next(&iter))
	{
		candidate = data_to_num(iter.data);
		if (candidate == num)
			return ((int)iter.pos);
	}
	return (-1);
}

void	sort3(t_stack *stack)
{
	t_lst	*l;
	int		max;
	int		min;
	int		mid;

	l = stack->a;
	get_min_max_mid(stack, &min, &max, &mid);
	if (get_pos(l, min) == 0 && get_pos(l, max) == 1 && get_pos(l, mid) == 2)
		do_2op(stack, SA, RA);
	if (get_pos(l, mid) == 0 && get_pos(l, min) == 1 && get_pos(l, max) == 2)
		do_op(stack, SA);
	if (get_pos(l, mid) == 0 && get_pos(l, max) == 1 && get_pos(l, min) == 2)
		do_op(stack, RRA);
	if (get_pos(l, max) == 0 && get_pos(l, min) == 1 && get_pos(l, mid) == 2)
		do_op(stack, RA);
	if (get_pos(l, max) == 0 && get_pos(l, mid) == 1 && get_pos(l, min) == 2)
		do_2op(stack, SA, RRA);
}
