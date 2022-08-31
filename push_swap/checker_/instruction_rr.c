#include "checker.h"

void	rra(t_stack *stack_a, int flag)
{
	t_list	*old_bottom;
	t_list	*new_bottom;

	old_bottom = NULL;
	new_bottom = NULL;
	if (stack_a->size == 1)
		return ;
	else if (stack_a->size == 2)
		sa(stack_a, 1);
	else
	{
		old_bottom = stack_a->bottom;
		new_bottom = old_bottom->prev;
		stack_a->bottom = new_bottom;
		old_bottom->prev = NULL;
		old_bottom->next = stack_a->top;
		new_bottom->next = NULL;
		(stack_a->top)->prev = old_bottom;
		stack_a->top = old_bottom;
	}
	if (flag == 0)
		ft_putstr("rra\n");
}

void	rrb(t_stack *stack_b, int flag)
{
	t_list	*old_bottom;
	t_list	*new_bottom;

	old_bottom = NULL;
	new_bottom = NULL;
	if (stack_b->size == 1)
		return ;
	else if (stack_b->size == 2)
		sb(stack_b, 1);
	else
	{
		old_bottom = stack_b->bottom;
		new_bottom = old_bottom->prev;
		stack_b->bottom = new_bottom;
		old_bottom->prev = NULL;
		old_bottom->next = stack_b->top;
		new_bottom->next = NULL;
		(stack_b->top)->prev = old_bottom;
		stack_b->top = old_bottom;
	}
	if (flag == 0)
		ft_putstr("rrb\n");
}

void	rrr(t_stack *stack_a, t_stack *stack_b, int flag)
{
	rra(stack_a, 1);
	rrb(stack_b, 1);
	if (flag == 0)
		ft_putstr("rrr\n");
}
