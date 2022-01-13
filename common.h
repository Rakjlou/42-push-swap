/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 23:36:19 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/13 09:13:57 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "libft.h"
# include "ftlst.h"

# define ERROR_MSG "Error"
# define OP_COUNT 11

typedef struct s_stack
{
	t_lst			*a;
	t_lst			*b;
	unsigned int	max_index;
}	t_stack;

typedef struct s_stack_print
{
	t_iter	a;
	t_iter	b;
	t_bool	a_print;
	t_bool	b_print;
}	t_stack_print;

typedef struct s_op
{
	char	*name;
	void	(*callback)(t_stack *);
}	t_op;

typedef struct s_num
{
	int				num;
	unsigned int	index;
}	t_num;

/* stack.c */
void			stack_print(t_stack *stack);
t_bool			stack_init(t_stack *stack);
void			stack_destroy(t_stack *stack);

/* load.c */
t_bool			load(t_stack *stack, int ac, char **av);

/* utils.c */
int				data_to_num(void *data);
unsigned int	data_to_index(void *data);
t_num			*malloc_num(int num);

/* op/ */
t_op			*get_ops(void);
void			pa(t_stack *stack);
void			pb(t_stack *stack);
void			ra(t_stack *stack);
void			rb(t_stack *stack);
void			rra(t_stack *stack);
void			rrb(t_stack *stack);
void			rr(t_stack *stack);
void			rrr(t_stack *stack);
void			sa(t_stack *stack);
void			sb(t_stack *stack);
void			ss(t_stack *stack);

#endif
