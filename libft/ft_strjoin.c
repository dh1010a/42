/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopaek <dopaek@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:34:25 by dopaek            #+#    #+#             */
/*   Updated: 2022/05/11 15:34:27 by dopaek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 || !s2)
		return (0);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	p = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!p)
		return (0);
	ft_strlcpy(p, s1, len_s1 + 1);
	ft_strlcat(p + len_s1, s2, len_s2 + 1);
	return (p);
}
