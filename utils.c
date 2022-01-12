/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 21:38:42 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/13 00:00:04 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <limits.h>

int	get_max(t_lst *stack)
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
			max = candidate;
	}
	return (max);
}

int	get_min(t_lst *stack)
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
			min = candidate;
	}
	return (min);
}

int	num_at(t_lst *lst, size_t pos)
{
	return (data_to_num(lst_data_at(lst, pos)));
}

int	data_to_num(void *data)
{
	int	*int_data;

	int_data = (int *)data;
	return (*int_data);
}

int	*malloc_num(int num)
{
	int	*m_num;

	m_num = ft_calloc(1, sizeof(int));
	if (m_num == NULL)
		return (NULL);
	*m_num = num;
	return (m_num);
}
