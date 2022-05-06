#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*cpy_dest;
	unsigned char	*cpy_src;
	size_t			i;

	if (!dest && !src)
		return (0);
	cpy_dest = dest;
	cpy_src = (unsigned char *)src;
	i = 0;
	while(i++ < n)
		*cpy_dest++ = *cpy_src++;
	return (dest);
}
