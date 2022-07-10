#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	l;
	char		c;

	l = n;
	c = '0';
	if (n < 0)
	{
		write(fd, "-", 1);
		l *= -1;
	}
	if (l >= 10)
	{
		ft_putnbr_fd(l / 10, fd);
		c += l % 10;
		write(fd, &c, 1);
	}
	else
	{
		c += l % 10;
		write(fd, &c, 1);
	}
}
