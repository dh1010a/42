#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		idx;
	int		size_s1;
	int		size_s2;
	char	*connected_s;

	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	connected_s = (char *)malloc(sizeof(char) * (size_s1 + size_s2) + 1);
	if (!connected_s)
		return (NULL);
	idx = 0;
	while (*s1)
		connected_s[idx++] = *s1++;
	while (*s2)
		connected_s[idx++] = *s2++;
	connected_s[idx] = '\0';
	return (connected_s);
}

char	*ft_strndup(const char *src, int start, int num)
{
	char	*temp;
	int		idx_s;
	int		idx_t;

	idx_s = 0;
	idx_t = 0;
	temp = (char *)malloc(sizeof(char) * num + 1);
	if (!temp)
		return (NULL);
	while (src[idx_s] && idx_t < num)
		temp[idx_t++] = src[start + idx_s++];
	temp[idx_t] = '\0';
	return (temp);
}
