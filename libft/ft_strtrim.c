/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopaek <dopaek@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:40:06 by dopaek            #+#    #+#             */
/*   Updated: 2022/05/11 15:40:07 by dopaek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*p;
	size_t		i;
	size_t		len;

	if (!s1 || !set)
		return (0);
	i = 0;
	len = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (s1[len - 1] && ft_strchr(set, s1[len - 1]) && len > i)
		len--;
	p = (char *)malloc(sizeof(char) * (len - i + 1));
	if (!p)
		return (0);
	ft_strlcpy(p, &s1[i], len - i + 1);
	return (p);
}
