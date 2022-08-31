#include "push_swap.h"

void	ft_sort_two(t_stack *stack_a)
{
	if ((stack_a->top)->data > (stack_a->bottom)->data)
		sa(stack_a, 0);
}

void	ft_sort_three(t_stack *stack_a, int min, int max)
{
	if ((stack_a->top)->data == min)
	{
		sa(stack_a, 0);
		ra(stack_a, 0);
	}
	else if ((stack_a->top)->data == max)
	{
		if ((stack_a->bottom)->data == min)
		{
			sa(stack_a, 0);
			rra(stack_a, 0);
		}
		else
			ra(stack_a, 0);
	}
	else
	{
		if ((stack_a->bottom)->data == min)
			rra(stack_a, 0);
		else
			sa(stack_a, 0);
	}
}

void	ft_sort_four(t_stack *stack_a, t_stack *stack_b)
{
	int		min;
	int		max;
	t_list	*cur;

	min = find_min(stack_a);
	max = find_max(stack_a);
	while (stack_b->size < 1)
	{
		cur = stack_a->top;
		if (cur->data == min || cur->data == max)
			pb(stack_a, stack_b, 0);
		else
			ra(stack_a, 0);
	}
	if (!already_sort(stack_a))
		ft_sort_three(stack_a, find_min(stack_a), find_max(stack_a));
	pa(stack_a, stack_b, 0);
	if (stack_a->top->data == max)
		ra(stack_a, 0);
}

void	ft_sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int		min;
	int		max;
	t_list	*cur;

	min = find_min(stack_a);
	max = find_max(stack_a);
	while (stack_b->size < 2)
	{
		cur = stack_a->top;
		if (cur->data == min || cur->data == max)
			pb(stack_a, stack_b, 0);
		else
			ra(stack_a, 0);
	}
	if (!already_sort(stack_a))
		ft_sort_three(stack_a, find_min(stack_a), find_max(stack_a));
	while (stack_b->size > 0)
	{
		pa(stack_a, stack_b, 0);
		if (stack_a->top->data == max)
			ra(stack_a, 0);
	}
}

void	ft_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 1 || already_sort(stack_a))
		return ;
	else if (stack_a->size == 2)
		ft_sort_two(stack_a);
	else if (stack_a->size == 3)
		ft_sort_three(stack_a, find_min(stack_a), find_max(stack_a));
	else if (stack_a->size == 4)
		ft_sort_four(stack_a, stack_b);
	else if (stack_a->size == 5)
		ft_sort_five(stack_a, stack_b);
	else
		ft_sort_more(stack_a, stack_b);
}
