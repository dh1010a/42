#include "../includes/ft_printf.h"

void	ft_putchari_fd(int c, int fd)
{
	char cc;

	cc = (char) c;
	write(fd, &cc, sizeof(c));
}
