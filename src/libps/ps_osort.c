/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_osort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:21:35 by rafernan          #+#    #+#             */
/*   Updated: 2021/11/24 11:40:27 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

static void	ps_osort3b(t_list **a, t_list **b)
{
	if (*b && (*b)->n && (long)(*b)->v < (long)(*b)->n->v
		&& (long)(*a)->v > (long)(*a)->n->n->v)
		ps_rr(a, b);
	else if ((long)(*a)->v > (long)(*a)->n->n->v)
		ps_rot(a, 'a');
	if (*b && (*b)->n && (long)(*b)->v < (long)(*b)->n->v
		&& (long)(*a)->v > (long)(*a)->n->v)
		ps_ss(a, b);
	else if ((long)(*a)->v > (long)(*a)->n->v)
		ps_swap(a, 'a');
}

void	ps_osort3(t_list **a, t_list **b)
{
	if (!(*a)->n->n)
	{
		if ((long)(*a)->v > (long)(*a)->n->v)
			ps_swap(a, 'a');
	}
	else if ((long)(*a)->v < (long)(*a)->n->v)
	{
		if (*b && (*b)->n && (long)(*b)->v < (long)(*b)->n->v
			&& (long)(*a)->n->v > (long)(*a)->n->n->v)
			ps_rrr(a, b);
		else if ((long)(*a)->n->v > (long)(*a)->n->n->v)
			ps_rrot(a, 'a');
		if (*b && (*b)->n && (long)(*b)->v < (long)(*b)->n->v
			&& (long)(*a)->v > (long)(*a)->n->v)
			ps_ss(a, b);
		else if ((long)(*a)->v > (long)(*a)->n->v)
			ps_swap(a, 'a');
	}
	else if ((long)(*a)->v > (long)(*a)->n->v)
		ps_osort3b(a, b);
}

void	ps_osort5(t_list **a, t_list **b, size_t a_siz, int avg)
{
	if (!a || !b || a_siz > 5)
		return ;
	while (a_siz > 3)
	{
		if ((long)(*a)->v <= avg)
		{
			ps_push(b, a, 'b');
			a_siz--;
		}
		else if ((long)(ft_lstlast(*a))->v <= avg)
			ps_rrot(a, 'a');
		else if ((long)(*a)->n->v <= avg)
			ps_swap(a, 'a');
		else
			ps_rot(a, 'a');
	}
	ps_osort3(a, b);
	if (*b && (*b)->n && (long)(*b)->v < (long)(*b)->n->v)
		ps_swap(b, 'b');
	while (*b)
		ps_push(a, b, 'a');
	if ((long)(*a)->v > (long)(*a)->n->v)
		ps_swap(a, 'a');
}
