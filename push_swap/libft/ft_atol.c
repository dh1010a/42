#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

static long	ft_sign(const char *str, long long *i)
{
	long		sign;
	long long	j;

	j = *i;
	sign = 1;
	if (str[j] == '-')
	{
		sign = -1;
		j++;
	}
	else if (str[j] == '+')
		j++;
	*i = j;
	return (sign);
}

long long	ft_atol(const char *str)
{
	long long	i;
	long		sign;
	long long	num;

	i = 0;
	num = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	sign = ft_sign(str, &i);
	while (str[i] != '\0' && ('0' <= str[i] && str[i] <= '9'))
	{
		num *= 10;
		num += (str[i] - '0');
		i++;
	}
	return (num * sign);
}
