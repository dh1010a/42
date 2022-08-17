NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c ft_printf_utils.c
OBJ = $(SRC:.c=.o)
INC_LINK = -I.

all : $(NAME)

$(NAME) : $(OBJ) libft
		$(MAKE) -C ./libft all
		cp libft/libft.a ./$(NAME)
		ar rsc $(NAME) $(OBJ)

%.o: %.c
	gcc $(FLAGS) $(INC_LINK) -c $< -o $(<:.c=.o)
	
clean :
	$(MAKE) -C ./libft fclean
	rm -rf $(OBJ)
fclean : clean	
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
