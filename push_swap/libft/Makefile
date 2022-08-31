CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
NAME = libft.a

SRCS = \
ft_atol.c ft_split.c ft_putstr.c \

OBJS = $(SRCS:.c=.o)
OBJECTS = $(OBJS)

%o : %c
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJECTS)
		ar rcs $(NAME) $(OBJECTS)


all : $(NAME)

clean :
		$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME)
re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY : all clean fclean re
