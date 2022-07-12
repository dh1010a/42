#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

# define INT_MIN -2147483648

int	ft_printf(const char *format, ...);
int	ft_printf_char(unsigned char c);
int	ft_printf_str(char *str);
int	ft_printf_nbr(int num);
int	ft_printf_ui(unsigned int num);
int	ft_printf_hex(unsigned long long num, int upper);
#endif
