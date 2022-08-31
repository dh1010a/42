#ifndef CHECKER_H
# define CHECKER_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

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

void	ft_read_instruction(t_stack *stack_a, t_stack *stack_b);
void	ft_print_result(t_stack *stack_a, t_stack *stack_b);
void	ft_checker_sort(t_stack *stack_a, t_stack *stack_b, char *inst);

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
void	stack_push_bottom(t_stack *stack, t_list *new);
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

int		find_min(t_stack *stack);
int		find_max(t_stack *stack);
int		already_sort(t_stack *stack);

#endif
