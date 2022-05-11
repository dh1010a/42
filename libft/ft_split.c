/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopaek <dopaek@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:45:28 by dopaek            #+#    #+#             */
/*   Updated: 2022/05/11 16:58:28 by dopaek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wordsize(char const *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if ((i == 0 && s[i] != c) || \
				(s[i] == c && s[i + 1] != c && s[i + 1] != '\0'))
				count ++;
		i++;
	}
	return (count);
}

char	*ft_strndup(const char *s, size_t n)
{
	size_t	i;
	char	*s_cpy;

	i = 0;
	s_cpy = 0;
	if (n == 0)
		return (0);
	s_cpy = (char *)malloc(sizeof(char) * (n + 1));
	if (!s_cpy)
		return (0);
	while (i < n)
	{
		s_cpy[i] = s[i];
		i++;
	}
	s_cpy[i] = '\0';
	return (s_cpy);
}

char	**all_free(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	j;
	size_t	tmp;

	arr = (char **)malloc(sizeof(char *) * (ft_wordsize(s, c) + 1));
	if (!arr || !s)
		return (0);
	i = 0;
	j = 0;
	while (i < ft_wordsize(s, c) && s[j] != '\0')
	{
		while (s[j] == c)
			j++;
		tmp = j;
		while (s[j] != c && s[j] != '\0')
			j++;
		arr[i] = ft_strndup(&s[tmp], j - tmp);
		if (arr[i++] == 0)
			return (all_free(arr));
	}
	arr[i] = 0;
	return (arr);
}
