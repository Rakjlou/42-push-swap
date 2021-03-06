/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 23:36:19 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/16 05:47:39 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "common.h"

typedef enum e_op_id
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

typedef struct s_flush
{
	unsigned int	total;
	unsigned int	rr;
	unsigned int	rb;
	unsigned int	ra;
	unsigned int	rrr;
	unsigned int	rrb;
	unsigned int	rra;
	unsigned int	apos;
	unsigned int	bpos;
}	t_flush;

/* op/utils.c */
void			do_op(t_stack *stack, t_op_id id);
void			do_2op(t_stack *stack, t_op_id id, t_op_id id2);
void			do_3op(t_stack *stack, t_op_id id, t_op_id id2, t_op_id id3);

/* utils.c */
unsigned int	index_at(t_lst *lst, size_t pos);
t_num			*data_at(t_lst *lst, size_t pos);
int				num_at(t_lst *lst, size_t pos);
int				get_max(t_lst *stack, unsigned int *pos);
int				get_min(t_lst *stack, unsigned int *pos);

/* build_indexes.c */
void			build_indexes(t_stack *stack);

/* sort/ */
unsigned int	find_position(t_stack *stack, t_num *num);
void			set_kept_nodes(t_stack *stack);
void			flush_a(t_stack *stack);
void			flush_b(t_stack *stack);
void			sort3(t_stack *stack);
void			sort5(t_stack *stack);
void			sort(t_stack *stack);

#endif
