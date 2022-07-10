#include "../includes/ft_printf.h"

void	ft_putlonglong_fd(int n, int fd)
{
	long long	l;
	char		c;

	l = (long long) n;
	c = '0';
	if (n < 0)
	{
		write(fd, "-", 1);
		l *= -1;
	}
	if (l >= 10)
	{
		ft_putlonglong_fd(l / 10, fd);
		c += l % 10;
		write(fd, &c, 1);
	}
	else
	{
		c += l % 10;
		write(fd, &c, 1);
	}
}
