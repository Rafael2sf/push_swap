/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:40:41 by rafernan          #+#    #+#             */
/*   Updated: 2021/11/22 13:45:26 by rafernan         ###   ########.fr       */
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
	while (*b && (*b)->n)
	{
		if ((L(*b)V) < L(*b)N)
			ps_swap(a, b, 'a');
	}
}

void	ps_step_1(t_list **a, t_list **b, int avg)
{
	// if last is smaller then top
	if ((L(*a)V) > (L(ft_lstlast(*a)V)))
		ps_rrot(a, 'a');
	/**/
	if ((L(*a)V) > (L(*a)N))
	{
		if (*b && (*b)->n && (L(*b)V) < (L(*b)N))
			ps_ss(a, b);
		else
			ps_swap(a, 'a');
	}
	// if a top is less then avg and is bigger then next
	if ((L(*a)V) > avg)
		ps_get_next(a, avg);
	ps_push(b, a, 'b');

	// ------------------------------------- //

	if (!*b || !(*b)->n)
		return ;
	// if b is smaller then nn
	if ((*b)->n->n && (L(*b)V) < (L(*b)NN))
	{
		/* if last is bigger then v */
		if ((L(*b)V) < (L(ft_lstlast(*b)V)))
		{
			/*
			ps_rrot(b, 'b');
			ps_swap(b, 'b');
			ps_rot(b, 'b');*/
		}
		ps_rot(b, 'b');
	}
	// if b is less then n
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
	while (*a && len > 3)
	{
		avg = ps_magic(ps_lstavg(*a, len), ps_lstmin(*a), ps_calcd());
		ps_step_1(a, b, avg);
		len = ft_lstsize(*a);
	}
	ps_osort3(a, b);
}
