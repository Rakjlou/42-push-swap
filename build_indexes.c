/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_indexes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 07:18:02 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/13 08:05:16 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ftprintf.h"
#include <limits.h>

static unsigned int	count_how_many_are_lesser(t_lst *lst, int ref)
{
	t_iter			iter;
	unsigned int	count;

	count = 0;
	iter_init(&iter, lst, ASC);
	while (iter_next(&iter))
	{
		if (data_to_num(iter.data) < ref)
			++count;
	}
	return (count);
}

void	build_indexes(t_lst *lst)
{
	t_iter	iter;
	t_num	*num;

	iter_init(&iter, lst, ASC);
	while (iter_next(&iter))
	{
		num = (t_num *)iter.data;
		num->index = count_how_many_are_lesser(lst, num->num);
	}
}
