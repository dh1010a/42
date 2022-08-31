#include "checker.h"

void	check_str_argument(char *argv, t_stack *stack_a)
{
	char	**split;
	t_list	*new_node;
	int		i;

	split = ft_split(argv, ' ');
	if (!split)
		error_handler(stack_a);
	i = 0;
	while (split[i])
	{
		if (!check_num(split[i]))
			error_handler(stack_a);
		if (!check_integer(ft_atol(split[i])))
			error_handler(stack_a);
		if (check_duplicate(ft_atol(split[i]), stack_a))
			error_handler(stack_a);
		new_node = init_new_node(ft_atol(split[i]));
		if (!new_node)
			error_handler(stack_a);
		stack_push_bottom(stack_a, new_node);
		i++;
	}
	if (!split[i - 1])
		error_handler(stack_a);
	split_free(split, i);
}

void	check_char_argument(char *argv, t_stack *stack_a)
{
	t_list	*new_node;

	if (!check_num(argv))
		error_handler(stack_a);
	if (!check_integer(ft_atol(argv)))
		error_handler(stack_a);
	if (check_duplicate(ft_atol(argv), stack_a))
		error_handler(stack_a);
	new_node = init_new_node(ft_atol(argv));
	if (!new_node)
		error_handler(stack_a);
	stack_push_bottom(stack_a, new_node);
}

void	make_stack_a(t_stack *stack_a, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (argv[i][0] == '\0')
			error_handler(stack_a);
		if (argv[i][1] != '\0')
			check_str_argument(argv[i++], stack_a);
		else
			check_char_argument(argv[i++], stack_a);
	}
}

t_stack	*init_stack(void)
{
	t_stack	*new_stack;

	new_stack = (t_stack *)malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->top = NULL;
	new_stack->bottom = NULL;
	new_stack->size = 0;
	return (new_stack);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = init_stack();
	if (!stack_a)
		exit(1);
	if (!argv[1][0])
		error_handler(stack_a);
	make_stack_a(stack_a, argv);
	if (already_sort(stack_a))
	{
		write(1, "OK\n", 3);
		return (0);
	}
	stack_b = init_stack();
	if (!stack_b)
		error_handler(stack_a);
	stack_indexing(stack_a);
	ft_read_instruction(stack_a, stack_b);
	ft_print_result(stack_a, stack_b);
	free(stack_b);
	return (0);
}
