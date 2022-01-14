/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 23:36:19 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/14 01:44:00 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <limits.h>
#include <stdio.h>

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
	if (i > 0)
		return (TRUE);
	return (FALSE);
}

static t_bool	load_num(t_stack *stack, int number)
{
	t_num	*num;

	num = malloc_num(number);
	if (num == NULL || !lst_push_back(stack->a, num))
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
	size_t	len;

	if (!valid_chars(arg))
		return (FALSE);
	len = ft_strlen(arg);
	num = ft_atol(arg);
	if (num > INT_MAX || num < INT_MIN || (long)(int)num != num || len > 11)
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
