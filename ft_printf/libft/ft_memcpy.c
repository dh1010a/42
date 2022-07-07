/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopaek <dopaek@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 15:31:32 by dopaek            #+#    #+#             */
/*   Updated: 2022/05/07 15:32:23 by dopaek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*cpy_dst;
	unsigned char	*cpy_src;
	size_t			i;

	if (!dst && !src)
		return (0);
	cpy_dst = (unsigned char *)dst;
	cpy_src = (unsigned char *)src;
	i = 0;
	while (i++ < n)
		*cpy_dst++ = *cpy_src++;
	return (dst);
}
