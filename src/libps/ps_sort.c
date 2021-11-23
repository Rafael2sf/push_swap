/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:40:41 by rafernan          #+#    #+#             */
/*   Updated: 2021/11/23 15:20:49 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"
#include <stdio.h>

#define V ->v
#define N ->n->v
#define NN ->n->n->v
#define L (long)
/*
void	ps_step_2(t_list **a, t_list **b)
{
	while (*b && (*b)->n)
	{
		// if smaller swap b
		if ((L(*b)V) < (L(*b)N))
			ps_swap(b, 'b');
		// if smaller reverse rotate b
		else if ((L(*b)V) < L(ft_lstlast(*b)V))
			ps_rrot(b, 'b');

		else if (L(ft_lstlast(*a)V) < (L(*a)V) && L(ft_lstlast(*a)V) > (L(*b)V))
			ps_rrot(a, 'a');
		// if b is smaller then a push
		else if ((L(*b)V) < (L(*a)V))
		{
			ps_push(a, b, 'a');
		}
		// find next smaller to push // Improve
		else
		{
			ps_get_next(b, (L(*a)V) - 1);
			ps_push(a, b, 'a');
		}
	}
}
*/

ssize_t	ps_lstmaxp(t_list *a, ssize_t len)
{
	t_list	*tmp;
	ssize_t	max;
	ssize_t	cur;
	ssize_t	i;

	if (!a)
		return (0);
	tmp = a;
	max = (ssize_t)((tmp)->v);
	cur = 0;
	i = 0;
	while (tmp)
	{
		if (max < (ssize_t)((tmp)->v))
		{
			max = (ssize_t)((tmp)->v);
			i = cur;
		}
		tmp = (tmp->n);
		cur++;
	}
	if (i > (len / 2))
		return (len - i);
	return (-i);
}

void	ps_step_2(t_list **a, t_list **b)
{
	ssize_t	maxp;

	while ((*b)->n)
	{
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
}

void	ps_step_1(t_list **a, t_list **b, int avg)
{
	/*
	// if last is smaller then top
	if ((L(*a)V) > (L(ft_lstlast(*a)V)))
		ps_rrot(a, 'a');
	if ((L(*a)V) > (L(*a)N))
	{
		if (*b && (*b)->n && (L(*b)V) < (L(*b)N))
			ps_ss(a, b);
		else
			ps_swap(a, 'a');
	} 
	// if a top is less then avg and is bigger then next */
	if ((L(*a)V) >= avg)
		ps_get_next(a, avg);
	ps_push(b, a, 'b');

	// ------------------------------------- //

	if (!*b || !(*b)->n)
		return ;
	// if b is smaller then nn
	if ((*b)->n->n && (L(*b)V) < (L(*b)NN))
		ps_rot(b, 'b');
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
	while (len > 2)
	{
		avg = ps_magic(ps_lstavg(*a, len), ps_lstmin(*a), ps_calcd(len));
		//ft_printf("(%d)", avg);
		ps_step_1(a, b, avg);
		len--;
	}
	ps_osort3(a, b);
	ps_step_2(a, b);
	ps_push(a, b, 'a');
	if ((long)(*a)->v > (long)(*a)->n->v)
		ps_swap(a, 'a');
}
