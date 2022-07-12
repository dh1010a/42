#include "ft_printf.h"

static int	ft_printf_format(const char type, va_list ap)
{
	int	len;

	if (type == 'c')
		len = ft_printf_char((unsigned char)va_arg(ap, int));
	else if (type == 's')
		len = ft_printf_str((char *)va_arg(ap, char *));
	else if (type == 'p')
	{
		len = write(1, "0x", 2);
		len += ft_printf_hex((unsigned long long)va_arg(ap, void *), 0);
	}
	else if (type == 'd' || type == 'i')
		len = ft_printf_nbr((int)va_arg(ap, int));
	else if (type == 'u')
		len = ft_printf_ui((unsigned int)va_arg(ap, int));
	else if (type == 'x')
		len = ft_printf_hex((unsigned int)va_arg(ap, int), 0);
	else if (type == 'X')
		len = ft_printf_hex((unsigned int)va_arg(ap, int), 1);
	else if (type == '%')
		len = write(1, "%", 1);
	else
		len = write(1, &type, 1);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	ap;

	len = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			len += ft_printf_format(*format, ap);
		}
		else
		{
			write(1, format, 1);
			len++;
		}
		if (*format)
			format++;
	}
	va_end(ap);
	return (len);
}
