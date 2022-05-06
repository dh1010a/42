#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *s_2;
	char find;

	s_2 = (char *) s;
	find = (char *) c;
	if (c == '\0')
	{
		while (*s_2)
			s_2++;
		return (s_2);
	}
	while (*s_2)
	{
		if (*s_2 == find)
			return (s_2);
		s_2++;
	}
	return (0);
}
