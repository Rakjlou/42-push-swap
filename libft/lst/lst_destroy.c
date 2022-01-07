/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 04:49:17 by nsierra-          #+#    #+#             */
/*   Updated: 2021/12/02 06:16:12 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlst.h"
#include <stdlib.h>

void	lst_destroy(t_lst **lst, void (*del)(void *))
{
	void	*data;
	t_lst	*list;

	list = *lst;
	while (42)
	{
		data = lst_pop_back(list, del);
		if (data == NULL)
			break ;
		if (del)
			del(data);
	}
	free(list);
	*lst = NULL;
}
