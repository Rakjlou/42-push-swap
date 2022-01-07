/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 00:30:31 by nsierra-          #+#    #+#             */
/*   Updated: 2021/12/02 02:34:15 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "ftprintf.h"
#include <stdarg.h>
#include <stddef.h>

static void	init_state(t_printf *state)
{
	state->current = STATE_DEFAULT;
	state->bytes_printed = 0;
	state->callback[STATE_DEFAULT] = state_default;
	state->callback[STATE_CONVERSION_FLAGS] = state_conversion_flags;
	state->callback[STATE_CONVERSION_LENGTH] = state_conversion_length;
	state->callback[STATE_CONVERSION_PRECISION] = state_conversion_precision;
	state->callback[STATE_CONVERSION_PRINT] = state_conversion_print;
	state->callback[STATE_WRONG_FLAG] = state_wrong_flag;
}

int	ftprintf(const char *format, ...)
{
	t_printf		state;
	unsigned int	current_state;

	if (format == NULL)
		return (-1);
	init_state(&state);
	va_start(state.args, format);
	while (state.current != STATE_END)
	{
		current_state = state.current;
		format = state.callback[current_state](format, &state);
	}
	va_end(state.args);
	return (state.bytes_printed);
}
