NAME = push_swap
NAME_BONUS = checker
LIBFT = libft
LIBFT_LIB = libft.a

SRCS = \
push_swap.c \
stack.c stack_indexing.c \
util_invalid_args.c util_free.c util_error.c \
instruction_ps.c instruction_r.c instruction_rr.c \
sort.c sort_util.c sort_more.c\

SRC_BONUS = \
checker_/checker.c checker_/util_checker.c \
checker_/get_next_line/get_next_line.c checker_/get_next_line/get_next_line_utils.c \
checker_/stack.c checker_/stack_indexing.c \
checker_/util_invalid_args.c checker_/util_free.c checker_/util_error.c \
checker_/instruction_ps.c checker_/instruction_r.c checker_/instruction_rr.c \
checker_/sort_util.c \

OBJS = $(SRCS:%.c=%.o)
OBJS_BONUS = $(SRC_BONUS:%.c=%.o)

LIBC = ar rc

CC = cc
CFLAGS = -Wall -Wextra -Werror

all	: $(NAME) $(NAME_BONUS)
$(NAME)	: $(OBJS)
		make all -C $(LIBFT)/
		cc $(CFLAGS) -o $(NAME) $(OBJS) -Llibft -lft
bonus : $(NAME_BONUS)
$(NAME_BONUS)	: $(OBJS_BONUS)
		make all -C $(LIBFT)/
		cc $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) -Llibft -lft


%.o	: %.c
		$(CC) $(CFLAGS) -c $^ -I./ -o $@


clean :
		rm -f $(OBJS)
		rm -f $(OBJS_BONUS)
		make clean -C $(LIBFT)

fclean : clean
		rm -f $(NAME)
		rm -f $(NAME_BONUS)
		rm -f $(LIBFT_LIB)
		make fclean -C $(LIBFT)

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY : all clean fclean re bonus
