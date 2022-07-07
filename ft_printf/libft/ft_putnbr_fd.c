/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopaek <dopaek@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:18:09 by dopaek            #+#    #+#             */
/*   Updated: 2022/05/11 16:18:10 by dopaek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	arr;

	if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_putnbr_fd(n / 10, fd);
			write(fd, "8", 1);
			return ;
		}
		else
		{
			write(fd, "-", 1);
			n *= -1;
		}
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		arr = n % 10 + '0';
	}
	else
		arr = n + '0';
	write(fd, &arr, 1);
}
