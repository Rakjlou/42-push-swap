/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_is_empty.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 02:44:22 by nsierra-          #+#    #+#             */
/*   Updated: 2021/12/02 02:50:52 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlst.h"

t_bool	lst_is_empty(t_lst *lst)
{
	if (lst->size == 0)
		return (TRUE);
	return (FALSE);
}