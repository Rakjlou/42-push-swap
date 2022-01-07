/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_default.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 23:08:59 by nsierra-          #+#    #+#             */
/*   Updated: 2021/12/02 02:34:08 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ftprintf.h"
#include <unistd.h>

static int	get_state(const char token)
{
	if (token == CONVERSION_CHARACTER)
		return (STATE_CONVERSION_FLAGS);
	else if (token == '\0')
		return (STATE_END);
	return (STATE_DEFAULT);
}

const char	*state_default(const char *format, t_printf *state)
{
	int	i;

	i = 0;
	while (format[i] && format[i] != CONVERSION_CHARACTER)
		i++;
	if (i != 0)
	{
		write(STDOUT_FILENO, format, i);
		state->bytes_printed += i;
	}
	state->current = get_state(format[i]);
	return (format + i);
}
