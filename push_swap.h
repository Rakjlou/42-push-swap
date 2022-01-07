#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ftlst.h"

# define ERROR_MSG "Error"

typedef struct s_stack
{
	t_lst	*a;
	t_lst	*b;
}	t_stack;

typedef struct s_stack_print
{
	t_iter	a;
	t_iter	b;
	t_bool	a_print;
	t_bool	b_print;
}	t_stack_print;

/* stack.c */
void	stack_print(t_stack *stack);
t_bool	stack_init(t_stack *stack);
void	stack_destroy(t_stack *stack);

/* load.c */
t_bool	load(t_stack *stack, int ac, char **av);

/* utils.c */
int	data_to_num(void *data);
int	*malloc_num(int num);

/* op/ */
void	pa(t_stack *stack);
void	pb(t_stack *stack);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rr(t_stack *stack);
void	rrr(t_stack *stack);
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack);

#endif
