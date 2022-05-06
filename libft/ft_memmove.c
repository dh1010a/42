#include "libft.h"

void *ft_memmove(void *dst, const void *src, size_t len)
{
    unsigned char	*cpy_dst;
	unsigned char	*cpy_src;

	cpy_dst = (unsigned char *) dst;
	cpy_src = (unsigned char *) src;
	if ((len == 0) || (!dest && !src))
		return (dst);
	if (cpy_dst <= cpy_src)
	{
		while (len-- > 0)
			*cpy_dst++ = *cpy_src++;
	}
	else
	{
		cpy_dst += len - 1;
		cpy_src += len - 1;
		while (len-- > 0)
			*cpy_dst-- = *cpy_src--;
	}
	return (dst);
}
