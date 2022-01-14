/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 21:38:42 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/14 01:40:50 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <limits.h>

int	get_max(t_lst *stack, unsigned int *pos)
{
	t_iter	iter;
	int		max;
	int		candidate;

	max = INT_MIN;
	iter_init(&iter, stack, ASC);
	while (iter_next(&iter))
	{
		candidate = data_to_num(iter.data);
		if (candidate > max)
		{
			max = candidate;
			if (pos != NULL)
				*pos = (unsigned int)iter.pos;
		}
	}
	return (max);
}

int	get_min(t_lst *stack, unsigned int *pos)
{
	t_iter	iter;
	int		min;
	int		candidate;

	min = INT_MAX;
	iter_init(&iter, stack, ASC);
	while (iter_next(&iter))
	{
		candidate = data_to_num(iter.data);
		if (candidate < min)
		{
			min = candidate;
			if (pos != NULL)
				*pos = (unsigned int)iter.pos;
		}
	}
	return (min);
}

int	num_at(t_lst *lst, size_t pos)
{
	return (data_to_num(lst_data_at(lst, pos)));
}

unsigned int	index_at(t_lst *lst, size_t pos)
{
	return (data_to_index(lst_data_at(lst, pos)));
}

t_num	*data_at(t_lst *lst, size_t pos)
{
	return ((t_num *)lst_data_at(lst, pos));
}
