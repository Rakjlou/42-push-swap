#include "push_swap.h"
#include <limits.h>

static t_bool	valid_chars(const char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
		{
			if (!(i == 0 && arg[i] == '-'))
				return (FALSE);
		}
		++i;
	}
	return (TRUE);
}

static t_bool	load_num(t_stack *stack, int num)
{
	int	*m_num;

	m_num = malloc_num(num);
	if (m_num == NULL || !lst_push_back(stack->a, m_num))
		return (FALSE);
	return (TRUE);
}

static t_bool	num_exists(t_stack *stack, int num)
{
	t_iter	iter;

	iter_init(&iter, stack->a, ASC);
	while (iter_next(&iter))
	{
		if (num == data_to_num(iter.data))
			return (TRUE);
	}
	return (FALSE);
}

static t_bool	check_validity(const char *arg, int *valid_num)
{
	long	num;

	if (!valid_chars(arg))
		return (FALSE);
	num = ft_atol(arg);
	if (num > INT_MAX || num < INT_MIN || (long)(int)num != num)
		return (FALSE);
	*valid_num = (int)num;
	return (TRUE);
}

t_bool	load(t_stack *stack, int ac, char **av)
{
	int	i;
	int	num;

	i = 1;
	if (!stack_init(stack))
		return (FALSE);
	while (i < ac)
	{
		if (!check_validity(av[i], &num)
			|| num_exists(stack, num)
			|| !load_num(stack, num))
			return (stack_destroy(stack), FALSE);
		++i;
	}
	return (TRUE);
}
