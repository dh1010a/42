#include "checker.h"

void	pa(t_stack *stack_a, t_stack *stack_b, int flag)
{
	t_list	*cur;

	cur = stack_pop_top(stack_b);
	stack_push_top(stack_a, cur);
	if (flag == 0)
		ft_putstr("pa\n");
}

void	pb(t_stack *stack_a, t_stack *stack_b, int flag)
{
	t_list	*cur;

	cur = stack_pop_top(stack_a);
	stack_push_top(stack_b, cur);
	if (flag == 0)
		ft_putstr("pb\n");
}

void	sa(t_stack *stack_a, int flag)
{
	t_list	*old_top;
	t_list	*new_top;

	if (stack_a->size == 1)
		return ;
	else if (stack_a->size == 2)
	{
		old_top = stack_pop_top(stack_a);
		stack_push_bottom(stack_a, old_top);
	}
	else
	{
		old_top = stack_pop_top(stack_a);
		new_top = stack_pop_top(stack_a);
		stack_push_top(stack_a, old_top);
		stack_push_top(stack_a, new_top);
	}
	if (flag == 0)
		ft_putstr("sa\n");
}

void	sb(t_stack *stack_b, int flag)
{
	t_list	*new_top;
	t_list	*old_top;

	if (stack_b->size == 1)
		return ;
	else if (stack_b->size == 2)
	{
		old_top = stack_pop_top(stack_b);
		stack_push_bottom(stack_b, old_top);
	}
	else
	{
		old_top = stack_pop_top(stack_b);
		new_top = stack_pop_top(stack_b);
		stack_push_top(stack_b, old_top);
		stack_push_top(stack_b, new_top);
	}
	if (flag == 0)
		ft_putstr("sb\n");
}

void	ss(t_stack *stack_a, t_stack *stack_b, int flag)
{
	sa(stack_a, 1);
	sb(stack_b, 1);
	if (flag == 0)
		ft_putstr("ss\n");
}
