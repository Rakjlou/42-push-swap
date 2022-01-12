#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "common.h"

typedef	enum	e_op_id
{
	PA,
	PB,
	RA,
	RB,
	RRA,
	RRB,
	RR,
	RRR,
	SA,
	SB,
	SS
}	t_op_id;

/* op/utils.c */
void	do_op(t_stack *stack, t_op_id id);
void	do_2op(t_stack *stack, t_op_id id, t_op_id id2);

/* utils.c */
int	num_at(t_lst *lst, size_t pos);
int	get_max(t_lst *stack);
int	get_min(t_lst *stack);

/* sort/ */
void	sort3(t_stack *stack);

#endif
