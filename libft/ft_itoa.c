/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopaek <dopaek@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:19:55 by dopaek            #+#    #+#             */
/*   Updated: 2022/05/11 16:19:57 by dopaek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_nlen(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len ++;
	while (n)
	{
		n /= 10;
		len ++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t	i;
	size_t	len;
	char	*arr;

	len = get_nlen(n);
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (0);
	arr[len] = '\0';
	i = 0;
	if (n < 0)
	{
		arr[0] = '-';
		i++;
	}
	while (i < len--)
	{
		if (n < 0)
			arr[len] = '0' + n % 10 * (-1);
		else
			arr[len] = '0' + n % 10;
		n /= 10;
	}
	return (arr);
}
