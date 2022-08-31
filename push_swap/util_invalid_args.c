#include "push_swap.h"

int	check_num(char *data)
{
	int			i;

	i = 0;
	if (data[i] == '-' || data[i] == '+')
		i++;
	if (!data[i])
		return (0);
	while (data[i])
	{
		if (data[i] < '0' || '9' < data[i])
			return (0);
		i++;
	}
	return (1);
}

int	check_integer(long long num)
{
	if (num < -2147483648)
		return (0);
	else if (2147483647 < num)
		return (0);
	else
		return (1);
}

int	check_duplicate(long long data, t_stack *stack)
{
	t_list	*cur;

	cur = stack->top;
	while (cur)
	{
		if (cur->data == data)
			return (1);
		cur = cur->next;
	}
	return (0);
}
