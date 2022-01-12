#include "push_swap.h"
#include <unistd.h>

void	do_op(t_stack *stack, t_op_id id)
{
	t_op	*op;

	op = &get_ops()[id];
	ft_putendl_fd(op->name, STDOUT_FILENO);
	op->callback(stack);
}

void	do_2op(t_stack *stack, t_op_id id, t_op_id id2)
{
	do_op(stack, id);
	do_op(stack, id2);
}

t_op	*get_ops(void)
{
	static t_op	op[OP_COUNT];

	op[0].name = "pa";
	op[0].callback = pa;
	op[1].name = "pb";
	op[1].callback = pb;
	op[2].name = "ra";
	op[2].callback = ra;
	op[3].name = "rb";
	op[3].callback = rb;
	op[4].name = "rra";
	op[4].callback = rra;
	op[5].name = "rrb";
	op[5].callback = rrb;
	op[6].name = "rr";
	op[6].callback = rr;
	op[7].name = "rrr";
	op[7].callback = rrr;
	op[8].name = "sa";
	op[8].callback = sa;
	op[9].name = "sb";
	op[9].callback = sb;
	op[10].name = "ss";
	op[10].callback = ss;
	return (op);
}
