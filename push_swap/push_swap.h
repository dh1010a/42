#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_list
{
	int				index;
	long long		data;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	int		size;
	t_list	*top;
	t_list	*bottom;
}	t_stack;

void	error_handler(t_stack *stack);
void	error_handler2(t_stack *stack_a, t_stack *stack_b);

void	split_free(char **tab, int index);
void	stack_free(t_stack *stack);

int		check_num(char *data);
int		check_duplicate(long long data, t_stack *stack);
int		check_integer(long long num);

void	check_str_argument(char *argv, t_stack *stack_a);
void	check_char_argument(char *argv, t_stack *stack_a);
void	make_stack_a(t_stack *stack_a, char **argv);
t_stack	*init_stack(void);

t_list	*init_new_node(long long data);
void	stack_push_top(t_stack *stack, t_list *node);
void	stack_push_bottom(t_stack *stack, t_list *new_node);
t_list	*stack_pop_top(t_stack *stack);

void	stack_indexing(t_stack *stack);
void	stack_indexing_2(t_stack *stack, int min, int min2, int i);

void	pa(t_stack *stack_a, t_stack *stack_b, int flag);
void	pb(t_stack *stack_a, t_stack *stack_b, int flag);
void	sa(t_stack *stack, int flag);
void	sb(t_stack *stack, int flag);
void	ss(t_stack *stack_a, t_stack *stack_b, int flag);
void	ra(t_stack *stack, int flag);
void	rb(t_stack *stack, int flag);
void	rr(t_stack *stack_a, t_stack *stack_b, int flag);
void	rra(t_stack *stack, int flag);
void	rrb(t_stack *stack, int flag);
void	rrr(t_stack *stack_a, t_stack *stack_b, int flag);

void	ft_sort(t_stack *stack_a, t_stack *stack_b);
void	ft_sort_two(t_stack *stack_a);
void	ft_sort_three(t_stack *stack_a, int min, int max);
void	ft_sort_four(t_stack *stack_a, t_stack *stack_b);
void	ft_sort_five(t_stack *stack_a, t_stack *stack_b);

int		find_min(t_stack *stack);
int		find_max(t_stack *stack);
int		already_sort(t_stack *stack);

void	ft_sort_more(t_stack *stack_a, t_stack *stack_b);
void	stack_a_to_b(t_stack *stack_a, t_stack *stack_b, int chunk, int i);
void	stack_b_to_a(t_stack *stack_a, t_stack *stack_b);
void	sort_b_max_top(t_stack *stack_b);
void	sort_a_rotate(t_stack *stack_a, int i, int chunk);

#endif
