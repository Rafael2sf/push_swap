/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 11:18:21 by rafernan          #+#    #+#             */
/*   Updated: 2021/10/21 11:29:41 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*res;
	t_list	*iter;

	if (!lst || !f || !del)
		return (NULL);
	iter = lst;
	tmp = ft_lstnew(f(iter->content));
	if (!tmp)
		return (NULL);
	res = tmp;
	iter = (iter->next);
	while (iter)
	{
		(tmp->next) = ft_lstnew(f(iter->content));
		if (!(tmp->next))
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		else
			tmp = (tmp->next);
		iter = (iter->next);
	}
	return (res);
}
