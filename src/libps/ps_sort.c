/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:40:41 by rafernan          #+#    #+#             */
/*   Updated: 2021/11/18 16:04:11 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"
#include <stdio.h>

void	ps_step_3(t_list **a, t_list **b, int len)
{
	int bvg;

	while (*b)
	{
		bvg = ps_lstavg(*b, len);
		if ((*b)->n && (long)((*b)->v) <= bvg)
			ps_rot(b, 'b');
		if ((*b)->n && (long)((*b)->v) < (long)((*b)->n->v))
		{
			/*if (*a && (*a)->n && ((long)(*a)->v) > ((long)(*a)->n->v))
				ps_ss(a ,b);
			else*/
				ps_swap(b, 'b');
		}
		else if ((*b)->n && (long)(ft_lstlast(*b)->v) > (long)((*b)->v) && (long)((*b)->v) > bvg)
			ps_rrot(b, 'b');
		else if ((long)((*b)->v) > (long)(*a)->v)
		{
			ps_push(b, a, 'b');
			ps_swap(b, 'b');
		}
		else
			ps_push(a, b, 'a');
		len = ft_lstsize(*b);
	}
}

/*
	if b is less then 'avg'  rot
	if b is smaller then next swap
*/
void	ps_step_2(t_list **a, t_list **b, int avg)
{
	(void)(a);
	if (!*b || !(*b)->n)
		return ;
	if (((long)(*b)->v) <= avg) // if next is ra then rr
		ps_rot(b, 'b');
	if (((long)(*b)->v) < ((long)(*b)->n->v))
	{
		if (*a && (*a)->n && ((long)(*a)->v) > ((long)(*a)->n->v))
			ps_ss(a ,b);
		else
			ps_swap(b, 'b');
	}
}

/*
	if a is less then val and last is smaller - rra
	if a is less then val and next is smaller - swap
	if a is less then val - push, else get_next
*/
void	ps_step_1(t_list **a, t_list **b, int val, int len)
{	
	(void)(len);
	// if a is bigger then last a -- rra, try rrr
	if (((long)(*a)->v) > (long)(ft_lstlast(*a)->v))
	{
		if (*b && (*b)->n && ((long)(*b)->v) < (long)(ft_lstlast(*b)->v)) // hmm
			ps_rrr(a, b);
		else
			ps_rrot(a, 'a');
	}
	// if a 
	if (((long)(*a)->v <= val && ((long)(*a)->v) > ((long)(*a)->n->v)))
	{
		if (*b && (*b)->n && ((long)(*b)->v) > ((long)(*b)->n->v)) // hmm
			ps_ss(a ,b);
		else
			ps_swap(a, 'a');
	}
	if (((long)(*a)->v) > val)
		ps_get_next(a, val);
	ps_push(b, a, 'b');
}

void	ps_sort(t_list **a, t_list **b)
{
	int	avg;
	int	len;
	
	len = ft_lstsize(*a);
	while (*a && len > 3)
	{
		avg = ps_magic(ps_lstavg(*a, len), ps_lstmin(*a), ps_calcd(len));
		ps_step_1(a, b, avg, len);
		ps_step_2(a, b, ps_lstavg(*b, 4));
		len = ft_lstsize(*a);
	}
	ps_osort3(a, b);
	ps_step_3(a, b, ft_lstsize(*b));
}
