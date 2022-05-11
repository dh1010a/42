/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopaek <dopaek@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:31:14 by dopaek            #+#    #+#             */
/*   Updated: 2022/05/07 16:31:15 by dopaek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_len >= dstsize)
		return (src_len + dstsize);
	while (*dst)
		dst++;
	if (dst_len < dstsize - 1 && dstsize > 0)
	{
		while (*src && dst_len + 1 + i < dstsize)
		{
			*dst++ = *src++;
			i++;
		}
		*dst = '\0';
	}
	return (dst_len + src_len);
}
