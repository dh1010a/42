#include "push_swap.h"

void	error_handler(t_stack *stack)
{
	write(2, "Error\n", 6);
	stack_free(stack);
	exit(1);
}

void	error_handler2(t_stack *stack_a, t_stack *stack_b)
{
	write(2, "Error\n", 6);
	stack_free(stack_a);
	stack_free(stack_b);
	exit(1);
}
