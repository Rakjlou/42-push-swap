/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 23:36:19 by nsierra-          #+#    #+#             */
/*   Updated: 2022/01/07 23:39:01 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "get_next_line.h"
#include "ftprintf.h"
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

static t_bool	find_and_call(
	t_stack *stack,
	t_op op[11],
	char *cmd,
	size_t len)
{
	int	i;

	i = 0;
	cmd[len - 1] = '\0';
	while (i < 11)
	{
		if (ft_strncmp(op[i].name, cmd, UINT_MAX) == 0)
		{
			op[i].callback(stack);
			return (TRUE);
		}
		++i;
	}
	return (FALSE);
}

static t_bool	execute_cmd(t_stack *stack, char *cmd, size_t len)
{
	t_op	op[11];

	op[0].name = "pa";
	op[0].callback = pa;
	op[1].name = "pb";
	op[1].callback = pb;
	op[2].name = "ra";
	op[2].callback = ra;
	op[3].name = "rb";
	op[3].callback = rb;
	op[4].name = "rra";
	op[4].callback = rra;
	op[5].name = "rrb";
	op[5].callback = rrb;
	op[6].name = "rr";
	op[6].callback = rr;
	op[7].name = "rrr";
	op[7].callback = rrr;
	op[8].name = "sa";
	op[8].callback = sa;
	op[9].name = "sb";
	op[9].callback = sb;
	op[10].name = "ss";
	op[10].callback = ss;
	return (find_and_call(stack, op, cmd, len));
}

static void	print_status(t_stack *stack)
{
	t_iter	iter;
	int		*last_num;

	if (stack->b->size > 0)
		ft_putendl_fd(KO_MSG, STDOUT_FILENO);
	else if (stack->a->size == 1)
		ft_putendl_fd(OK_MSG, STDOUT_FILENO);
	else
	{
		iter_init(&iter, stack->a, ASC);
		last_num = NULL;
		while (iter_next(&iter))
		{
			if (last_num != NULL && *last_num > data_to_num(iter.data))
			{
				ft_putendl_fd(KO_MSG, STDOUT_FILENO);
				return ;
			}
			last_num = iter.data;
		}
		ft_putendl_fd(OK_MSG, STDOUT_FILENO);
	}
}

static void	read_cmds(t_stack *stack)
{
	char	*line;
	size_t	len;
	int		error;

	error = 0;
	while (42)
	{
		line = get_next_line(STDIN_FILENO);
		if (line == NULL)
			break ;
		else if (error == 0)
		{
			len = ft_strlen(line);
			if (ft_strlen(line) < 2 || !execute_cmd(stack, line, len))
				error = 1;
			else
				stack_print(stack);
		}
		free(line);
	}
	if (error == 1)
		ft_putendl_fd(ERROR_MSG, STDERR_FILENO);
	else
		print_status(stack);
}

int	main(int ac, char **av)
{
	t_stack	stack;

	stack.a = NULL;
	stack.b = NULL;
	if (ac <= 1)
		return (EXIT_FAILURE);
	else if (!load(&stack, ac, av))
		return (ft_putendl_fd(ERROR_MSG, STDERR_FILENO), EXIT_FAILURE);
	read_cmds(&stack);
	stack_destroy(&stack);
	return (0);
}
