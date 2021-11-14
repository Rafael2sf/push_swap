/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_listfind.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:41:42 by rafernan          #+#    #+#             */
/*   Updated: 2021/11/13 16:05:05 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

int	ps_lstfind(t_list *s, int nbr)
{
	t_list	*tmp;

	tmp = s;
	while (tmp)
	{
		if ((long)(tmp->content) == nbr)
			return (1);
		tmp = (tmp->next);
	}
	return (0);
}


int	ps_lstf_bigger(t_list *s, int nbr, size_t depth)
{
	t_list	*tmp;

	tmp = s;
	while (tmp && depth)
	{
		if ((long)(tmp->content) > nbr)
			return (1);
		tmp = (tmp->next);
		depth--;
	}
	return (0);
}
