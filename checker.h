#ifndef CHECKER_H
# define CHECKER_H

# include "common.h"

# define KO_MSG "KO"
# define OK_MSG "OK"

typedef struct s_op
{
	char	*name;
	void	(*callback)(t_stack *);
}	t_op;

#endif
