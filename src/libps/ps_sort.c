/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:40:41 by rafernan          #+#    #+#             */
/*   Updated: 2021/11/23 16:55:56 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"
#include <stdio.h>

#define V ->v
#define N ->n->v
#define NN ->n->n->v
#define L (long)

void	ps_step_2(t_list **a, t_list **b)
{
	ssize_t	maxp;

	maxp = ps_lstmaxp(*b, ft_lstsize(*b));
	if (maxp == -1)
		ps_swap(b, 'b');
	else
	{
		while (maxp > 0)
		{
			ps_rrot(b, 'b');
			maxp--;
		}
		while (maxp < 0)
		{
			ps_rot(b, 'b');
			maxp++;
		}
	}
	ps_push(a, b, 'a');
	if ((long)(*a)->v > (long)(*a)->n->v)
		ps_swap(a, 'a');
}

void	ps_step_1(t_list **a, t_list **b, int avg)
{
	if ((L(*a)V) >= avg)
		ps_get_next(a, avg);
	ps_push(b, a, 'b');
	if (!*b || !(*b)->n)
		return ;
	if ((*b)->n->n && (L(*b)V) < (L(*b)NN))
		ps_rot(b, 'b');
	if ((L(*b)V) < (L(*b)N))
	{
		if ((L(*a)V) < (L(*a)N))
			ps_ss(a, b);
		else
			ps_swap(b, 'b');
	}
}

void	ps_sort(t_list **a, t_list **b)
{
	int	avg;
	int	len;

	len = ft_lstsize(*a);
	while (len > 3)
	{
		avg = ps_nmax(ps_lstavg(*a, len), ps_lstmin(*a), ps_calcd(len));
		ps_step_1(a, b, avg);
		len--;
	}
	len = ft_lstsize(*b);
	ps_osort3(a, b);
	while (len > 1)
	{
		ps_step_2(a, b);
		len--;
	}
	ps_push(a, b, 'a');
	if ((long)(*a)->v > (long)(*a)->n->v)
		ps_swap(a, 'a');
}
