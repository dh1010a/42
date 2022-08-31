#include "push_swap.h"

int	find_min(t_stack *stack)
{
	int		min;
	t_list	*cur;

	min = (stack->top)->data;
	cur = stack->top;
	while (cur)
	{
		if (cur->data < min)
			min = cur->data;
		cur = cur->next;
	}
	return (min);
}

int	find_max(t_stack *stack)
{
	int		max;
	t_list	*cur;

	max = (stack->top)->data;
	cur = stack->top;
	while (cur)
	{
		if (cur->data > max)
			max = cur->data;
		cur = cur->next;
	}
	return (max);
}

int	already_sort(t_stack *stack)
{
	t_list	*cur;

	cur = stack->top;
	while (cur->next)
	{
		if (cur->data < cur->next->data)
			cur = cur->next;
		else
			return (0);
	}
	return (1);
}
