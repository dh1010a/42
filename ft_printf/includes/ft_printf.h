#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

void	ft_putchari_fd(int c, int fd);
void	ft_putlonglong_fd(int n, int fd);
void	ft_putpointer_fd(void *pointer, int fd);
void	ft_putuint_fd(int i, int fd);
void	ft_putlowerhex_fd(int i, int fd);
void	ft_putupperhex_fd(int i, int fd);
int		ft_printf(const char *input, ...);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);


#endif
