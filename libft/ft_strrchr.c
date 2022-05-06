#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*s_2;
	char	find;
	char	*tmp;

	s_2 = (char *) s;
	find = (char) c;
	tmp = 0;
	if (c == '\0')
	{
		while (*s_2)
			s_2++;
		return (s_2);
	}
	while (*s_2)
	{
		if (*s_2 == find)
			tmp = s_2;
		s_2++;
	}
	return (tmp);
}
