/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopaek <dopaek@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:23:50 by dopaek            #+#    #+#             */
/*   Updated: 2022/05/11 11:23:51 by dopaek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*s_2;
	char	find;

	s_2 = (char *) s;
	find = (char ) c;
	if (c == '\0')
	{
		while (*s_2)
			s_2++;
		return (s_2);
	}
	while (*s_2)
	{
		if (*s_2 == find)
			return (s_2);
		s_2++;
	}
	return (0);
}
