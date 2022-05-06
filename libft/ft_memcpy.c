#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*cpy_dst;
	unsigned char	*cpy_src;
	size_t			i;

	if (!dst && !src)
		return (0);
	cpy_dst = (unsigned char *)dst;
	cpy_src = (unsigned char *)src;
	i = 0;
	while(i++ < n)
		*cpy_dest++ = *cpy_src++;
	return (dst);
}
