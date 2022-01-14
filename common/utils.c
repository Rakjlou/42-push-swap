/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_common.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 01:39:28 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/14 01:40:18 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	data_to_num(void *data)
{
	t_num	*num;

	num = (t_num *)data;
	return (num->num);
}

unsigned int	data_to_index(void *data)
{
	t_num	*num;

	num = (t_num *)data;
	return (num->index);
}

t_num	*malloc_num(int number)
{
	t_num	*num;

	num = ft_calloc(1, sizeof(t_num));
	if (num == NULL)
		return (NULL);
	num->num = number;
	num->index = 0;
	return (num);
}
