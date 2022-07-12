#include "ft_printf.h"

int	ft_printf_char(unsigned char c)
{
	int		len;

	len = write(1, &c, 1);
	return (len);
}

int	ft_printf_str(char *str)
{
	int		len;

	if (!str)
		len = ft_printf_str("(null)");
	else
		len = write(1, str, ft_strlen(str));
	return (len);
}

int	ft_printf_nbr(int num)
{
	int		len;
	char	*str;

	str = ft_itoa(num);
	if (!str)
		return (INT_MIN);
	len = write(1, str, ft_strlen(str));
	free(str);
	return (len);
}

int	ft_printf_ui(unsigned int num)
{
	int	len;

	if (num > 9)
	{
		len = ft_printf_nbr(num / 10);
		len += ft_printf_char(num % 10 + '0');
	}
	else
		len = ft_printf_char(num + '0');
	return (len);
}

int	ft_printf_hex(unsigned long long num, int upper)
{
	int			len;
	static char	*lower_base = "0123456789abcdef";
	static char	*upper_base = "0123456789ABCDEF";

	len = 0;
	if (num < 16)
	{
		if (upper)
			len += ft_printf_char(upper_base[num]);
		else
			len += ft_printf_char(lower_base[num]);
	}
	else
	{
		len += ft_printf_hex(num / 16, upper);
		len += ft_printf_hex(num % 16, upper);
	}	
	return (len);
}
