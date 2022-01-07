/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_wrong_flag.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:29:17 by nsierra-          #+#    #+#             */
/*   Updated: 2021/12/02 02:34:06 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
#include <unistd.h>

const char	*state_wrong_flag(const char *format, t_printf *state)
{
	const char	*returned;

	returned = state->op.start;
	ft_bzero(&state->op, sizeof(t_printf_op));
	write(STDOUT_FILENO, "%", 1);
	state->bytes_printed += 1;
	state->current = STATE_DEFAULT;
	(void)format;
	return (++returned);
}
