/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_character.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 22:15:41 by nsierra-          #+#    #+#             */
/*   Updated: 2021/12/02 02:34:13 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
#include <unistd.h>

static void	print_padding(size_t size)
{
	size_t	i;

	i = 0;
	while (i++ < size)
		write(STDOUT_FILENO, " ", 1);
}

void	print_character(t_printf *state)
{
	int				raw;
	unsigned char	to_print;

	raw = va_arg(state->args, int);
	to_print = (unsigned int)raw;
	if (state->op.length == FALSE || state->op.length_value < 2)
	{
		write(STDOUT_FILENO, &to_print, 1);
		state->bytes_printed += 1;
		return ;
	}
	else if (state->op.justified_left == TRUE)
	{
		write(STDOUT_FILENO, &to_print, 1);
		print_padding(state->op.length_value - 1);
	}
	else
	{
		print_padding(state->op.length_value - 1);
		write(STDOUT_FILENO, &to_print, 1);
	}
	state->bytes_printed += (int)state->op.length_value;
}
