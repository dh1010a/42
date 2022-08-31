#include "push_swap.h"

t_list	*init_new_node(long long data)
{
	t_list	*newnode;

	newnode = (t_list *)malloc(sizeof(*newnode));
	if (!newnode)
		return (NULL);
	newnode->index = 0;
	newnode->data = data;
	newnode->prev = NULL;
	newnode->next = NULL;
	return (newnode);
}

void	stack_push_top(t_stack *stack, t_list *node)
{
	if (node)
	{
		if (stack->top)
		{
			node->next = stack->top;
			(stack->top)->prev = node;
			stack->top = node;
		}
		else
		{
			stack->top = node;
			stack->bottom = node;
		}
		(stack->size)++;
	}
}

void	stack_push_bottom(t_stack *stack, t_list *new_node)
{
	t_list	*bottom;

	if (new_node)
	{
		if (!(stack->top))
		{
			stack->top = new_node;
			stack->bottom = new_node;
		}
		else
		{
			bottom = stack->bottom;
			new_node->prev = bottom;
			bottom->next = new_node;
			stack->bottom = new_node;
		}
	}
	(stack->size)++;
}

t_list	*stack_pop_top(t_stack *stack)
{
	t_list	*cur;

	if (stack->top)
	{
		if (stack->top->next)
		{
			cur = stack->top;
			(cur->next)->prev = NULL;
			stack->top = cur->next;
			cur->next = NULL;
		}
		else
		{
			cur = stack->top;
			stack->top = NULL;
			stack->bottom = NULL;
		}
		(stack->size)--;
		return (cur);
	}
	else
		return (NULL);
}
