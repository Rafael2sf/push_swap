/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_listfind.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:41:42 by rafernan          #+#    #+#             */
/*   Updated: 2021/11/16 12:07:54 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

int	ps_lstfind(t_list *s, int nbr)
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

int	ps_lstf_bigger(t_list *s, int nbr, size_t depth)
{
	t_list	*tmp;

	tmp = s;
	while (tmp && depth)
	{
		if ((long)(tmp->v) > nbr)
			return (1);
		tmp = (tmp->n);
		depth--;
	}
	return (0);
}
