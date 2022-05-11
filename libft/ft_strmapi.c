/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopaek <dopaek@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:06:38 by dopaek            #+#    #+#             */
/*   Updated: 2022/05/11 16:06:39 by dopaek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char		*arr;
	size_t		i;
	size_t		s_len;

	i = 0;
	if (!s || !f)
		return (0);
	s_len = ft_strlen(s);
	arr = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!arr)
		return (0);
	while (i < s_len)
	{
		arr[i] = f(i, s[i]);
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
