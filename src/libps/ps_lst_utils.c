/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:41:42 by rafernan          #+#    #+#             */
/*   Updated: 2021/11/23 15:10:05 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

int		ps_lstfind(t_list *s, int nbr)
{
	t_list	*tmp;

	tmp = s;
	while (tmp)
	{
		if ((long)(tmp->v) == nbr)
			return (1);
		tmp = (tmp->n);
	}
	return (0);
}

int		ps_lstmin(t_list *a)
{
	int		min;
	t_list	*tmp;

	tmp = a;
	min = INT_MAX;
	while (tmp)
	{
		if (min > (int)(long)((tmp)->v))
			min = (int)(long)((tmp)->v);
		tmp = (tmp->n);
	}
	return (min);
}
