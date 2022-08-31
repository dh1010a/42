#include "checker.h"

void	split_free(char **tab, int index)
{
	int	i;

	i = 0;
	while (i < index)
		free(tab[i++]);
	free(tab);
}

void	stack_free(t_stack *stack)
{
	t_list	*cur;
	int		i;
	int		size;

	i = 0;
	size = stack->size;
	while (i < size)
	{
		cur = stack_pop_top(stack);
		free(cur);
		i++;
	}
	free(stack);
}
