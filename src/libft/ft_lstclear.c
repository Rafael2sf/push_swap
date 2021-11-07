/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 11:12:12 by rafernan          #+#    #+#             */
/*   Updated: 2021/11/07 12:59:25 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*nxtptr;

	if (!lst || !*lst)
		return ;
	tmp = *lst;
	while (tmp)
	{
		nxtptr = (tmp->next);
		if (del)
			del(tmp->content);
		free(tmp);
		tmp = nxtptr;
	}
	*lst = NULL;
}
