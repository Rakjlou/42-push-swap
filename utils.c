#include "push_swap.h"

int	data_to_num(void *data)
{
	int	*int_data;

	int_data = (int *)data;
	return (*int_data);
}

int	*malloc_num(int num)
{
	int	*m_num;

	m_num = ft_calloc(1, sizeof(int));
	if (m_num == NULL)
		return (NULL);
	*m_num = num;
	return (m_num);
}
