#include "checker.h"

void	ra(t_stack *stack_a, int flag)
{
	t_list	*old_top;

	old_top = NULL;
	if (stack_a->size == 1)
		return ;
	else if (stack_a->size == 2)
		sa(stack_a, 1);
	else
	{
		old_top = stack_pop_top(stack_a);
		stack_push_bottom(stack_a, old_top);
	}
	if (flag == 0)
		ft_putstr("ra\n");
}

void	rb(t_stack *stack_b, int flag)
{
	t_list	*old_top;

	old_top = NULL;
	if (stack_b->size == 1 || stack_b->size == 0)
		return ;
	else if (stack_b->size == 2)
		sb(stack_b, 1);
	else
	{
		old_top = stack_pop_top(stack_b);
		stack_push_bottom(stack_b, old_top);
	}
	if (flag == 0)
		ft_putstr("rb\n");
}

void	rr(t_stack *stack_a, t_stack *stack_b, int flag)
{
	ra(stack_a, 1);
	rb(stack_b, 1);
	if (flag == 0)
		ft_putstr("rr\n");
}
