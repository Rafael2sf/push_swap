/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_get_next.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:52:05 by rafernan          #+#    #+#             */
/*   Updated: 2021/11/25 11:58:36 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

static size_t	ps_calc_ra(t_list *a, int val)
{
	t_list	*tmp;
	size_t	i;

	i = 0;
	tmp = a;
	while (tmp)
	{
		if (((long)(tmp->v)) <= val)
			break ;
		tmp = (tmp->n);
		i++;
	}
	return (i);
}

static size_t	ps_calc_rra(t_list *a, int val)
{
	t_list	*tmp;
	size_t	cur;
	size_t	i;

	i = 0;
	cur = 0;
	tmp = a;
	while (tmp)
	{
		if (((long)(tmp->v)) <= val)
			cur = i;
		tmp = (tmp->n);
		i++;
	}
	return (i - cur);
}

void	ps_get_next(t_list **a, int val)
{
	size_t	ra;
	size_t	rra;

	ra = ps_calc_ra(*a, val);
	rra = ps_calc_rra(*a, val);
	if (ra <= rra)
	{
		while (*a && (*a)->n && ra--)
			ps_rot(a, 'a');
	}
	else
	{
		while (*a && (*a)->n && rra--)
			ps_rrot(a, 'a');
	}
}
