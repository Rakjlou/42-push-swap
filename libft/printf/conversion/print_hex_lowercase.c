/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 22:15:41 by nsierra-          #+#    #+#             */
/*   Updated: 2021/12/02 02:34:12 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
#include <stdlib.h>
#include <unistd.h>

static char	*apply_flags(t_printf *state, unsigned int raw, char *to_print)
{
	to_print = apply_special_cases(state, (int)raw, to_print);
	to_print = apply_precison_flag(state, 1, to_print);
	to_print = apply_sharp_flag(state, to_print, "0x");
	to_print = apply_length_flag(state, to_print);
	return (to_print);
}

void	print_hex_lowercase(t_printf *state)
{
	unsigned int	raw;
	char			*to_print;
	size_t			to_print_size;

	raw = va_arg(state->args, unsigned int);
	to_print = ft_utoa_base(raw, "0123456789abcdef", 16);
	if (to_print == NULL)
		return ;
	to_print = apply_flags(state, raw, to_print);
	to_print_size = ft_strlen(to_print);
	write(STDOUT_FILENO, to_print, to_print_size);
	state->bytes_printed += (int)to_print_size;
	free(to_print);
}
