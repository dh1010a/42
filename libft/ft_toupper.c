#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		retrun (c - 32);
	return (c);
}
