#include "checker.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (!*s)
			return (0);
		s++;
	}
	return ((char *)s);
}

int	ft_strncmp(const char *s1, const char *s2, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (0);
	while (i < size - 1)
	{
		if (s1[i] && s2[i] && s1[i] == s2[i])
			i++;
		else
			break ;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_checker_sort(t_stack *stack_a, t_stack *stack_b, char *inst)
{
	if (!ft_strncmp("pa\n", inst, 3))
		pa(stack_a, stack_b, 1);
	else if (!ft_strncmp("pb\n", inst, 3))
		pb(stack_a, stack_b, 1);
	else if (!ft_strncmp("sa\n", inst, 3))
		sa(stack_a, 1);
	else if (!ft_strncmp("sb\n", inst, 3))
		sb(stack_b, 1);
	else if (!ft_strncmp("ss\n", inst, 3))
		ss(stack_a, stack_b, 1);
	else if (!ft_strncmp("ra\n", inst, 3))
		ra(stack_a, 1);
	else if (!ft_strncmp("rra\n", inst, 4))
		rra(stack_a, 1);
	else if (!ft_strncmp("rb\n", inst, 3))
		rb(stack_a, 1);
	else if (!ft_strncmp("rrb\n", inst, 4))
		rrb(stack_a, 1);
	else if (!ft_strncmp("rr\n", inst, 3))
		rr(stack_a, stack_b, 1);
	else if (!ft_strncmp("rrr\n", inst, 4))
		rrr(stack_a, stack_b, 1);
	else
		error_handler2(stack_a, stack_b);
}

void	ft_read_instruction(t_stack *stack_a, t_stack *stack_b)
{
	char	*inst;

	inst = get_next_line(STDIN_FILENO);
	while (inst)
	{
		if (ft_strchr(inst, 4))
			break ;
		ft_checker_sort(stack_a, stack_b, inst);
		inst = get_next_line(STDIN_FILENO);
	}
}

void	ft_print_result(t_stack *stack_a, t_stack *stack_b)
{
	if (already_sort(stack_a) && !(stack_b->top))
		write(1, "OK\n", 3);
	else if (!already_sort(stack_a) || stack_b->top)
		write(1, "KO\n", 3);
	else
		write(1, "Error\n", 6);
}
