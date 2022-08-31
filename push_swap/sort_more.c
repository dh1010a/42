#include "push_swap.h"

void	sort_b_max_top(t_stack *stack_b)
{
	int		i;
	t_list	*cur;

	i = 0;
	cur = stack_b->top;
	while (cur)
	{
		if (cur->index == stack_b->size - 1)
			break ;
		i++;
		cur = cur->next;
	}
	while ((stack_b->top)->index < stack_b->size - 1)
	{
		if (i < stack_b->size / 2)
			rb(stack_b, 0);
		else
			rrb(stack_b, 0);
	}
}

void	sort_a_rotate(t_stack *stack_a, int i, int chunk)
{
	int		mid;
	t_list	*cur;

	mid = 0;
	cur = stack_a->top;
	while (cur)
	{
		if (cur->index <= i + chunk)
			break ;
		mid++;
		cur = cur->next;
	}
	if (mid < stack_a->size / 2)
		ra(stack_a, 0);
	else if (i < (stack_a->size / 2))
		rra(stack_a, 0);
	else
		ra(stack_a, 0);
}

void	stack_a_to_b(t_stack *stack_a, t_stack *stack_b, int chunk, int i)
{
	t_list	*top;
	t_list	*top_b;

	while (stack_a->size > 0)
	{
		top = stack_a->top;
		top_b = stack_b->top;
		if (top->index <= i)
		{
			pb(stack_a, stack_b, 0);
			i++;
		}
		else if (top->index > i && top->index <= i + chunk)
		{
			pb(stack_a, stack_b, 0);
			rb(stack_b, 0);
			i++;
		}
		else
			sort_a_rotate(stack_a, i, chunk);
		if (stack_b->size > 4 && top_b->index < (top_b->next)->index)
			sb(stack_b, 0);
	}
}

void	stack_b_to_a(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b->size > 0)
	{
		sort_b_max_top(stack_b);
		pa(stack_a, stack_b, 0);
	}
}

void	ft_sort_more(t_stack *stack_a, t_stack *stack_b)
{
	int	chunk;
	int	x;

	x = stack_a->size;
	chunk = 0.000000053 * x * x + 0.03 * x + 14.5;
	stack_a_to_b(stack_a, stack_b, chunk, 0);
	stack_b_to_a(stack_a, stack_b);
}
