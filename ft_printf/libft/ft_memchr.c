/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopaek <dopaek@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:31:36 by dopaek            #+#    #+#             */
/*   Updated: 2022/05/07 16:31:36 by dopaek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	target;

	target = (unsigned char)c;
	while (n > 0)
	{
		if (*(unsigned char *)s == target)
			return ((void *)s);
		s++;
		n--;
	}
	return (0);
}
