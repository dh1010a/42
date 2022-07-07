/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopaek <dopaek@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:18:33 by dopaek            #+#    #+#             */
/*   Updated: 2022/03/22 14:18:34 by dopaek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*cpy;
	unsigned char	n;
	size_t			i;

	cpy = b;
	n = c;
	i = 0;
	while (i++ < len)
		*cpy++ = n;
	return (b);
}
