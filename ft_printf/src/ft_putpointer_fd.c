#include "../includes/ft_printf.h"

void	ft_putpointer_fd(void *pointer, int fd)
{
	unsigned long	p;
	int				cnt;
	int				idx;
	char			hexp[100];

	p = (unsigned long) pointer;
	cnt = 0;
	write(fd, "0x", 2);
	while (p > 0)
	{
		hexp[cnt++] = p % 16;
		p /= 16;
	}
	idx = 0;
	while (idx < cnt)
	{
		if (hexp[idx] < 10)
			hexp[idx] = hexp[idx] + 48;
		else
			hexp[idx] = hexp[idx] + 87;
		idx++;
	}
	while (idx > 0)
		write(fd, &hexp[idx-- - 1], 1);
}
