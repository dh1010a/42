/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopaek <dopaek@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:47:11 by dopaek            #+#    #+#             */
/*   Updated: 2022/05/11 16:47:12 by dopaek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n_node;
	t_list	*n_list;
	t_list	*tmp;

	tmp = lst;
	n_list = 0;
	while (tmp)
	{
		n_node = ft_lstnew(f(tmp->content));
		if (!n_node)
		{
			ft_lstclear(&n_list, del);
			return (0);
		}
		ft_lstadd_back(&n_list, n_node);
		tmp = tmp->next;
	}
	n_node = 0;
	return (n_list);
}
