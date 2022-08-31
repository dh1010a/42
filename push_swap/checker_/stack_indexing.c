#include "checker.h"

void	stack_indexing_2(t_stack *stack, int min, int min2, int i)
{
	t_list	*cur;

	while (++i < stack->size)
	{
		cur = stack->top;
		while (cur)
		{
			if (min < cur->data && cur->data < min2)
				min2 = cur->data;
			cur = cur->next;
		}
		cur = stack->top;
		while (cur)
		{
			if (cur->data == min2)
			{
				cur->index = i;
				break ;
			}	
			cur = cur->next;
		}
		min = min2;
		min2 = find_max(stack);
	}
}

void	stack_indexing(t_stack *stack)
{
	int		min;
	t_list	*cur;

	min = find_min(stack);
	cur = stack->top;
	while (cur)
	{
		if (cur->data == min)
		{
			cur->index = 0;
			break ;
		}
		else
			cur = cur->next;
	}
	stack_indexing_2(stack, min, find_max(stack), 0);
}
