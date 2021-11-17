/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:40:41 by rafernan          #+#    #+#             */
/*   Updated: 2021/11/17 16:31:30 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"
#include <stdio.h>

#define DIVISOR 15

void	ps_step_3(t_list **a, t_list **b, int len)
{
	long bvg;

	while (len > 4)
	{
		len = ft_lstsize(*b);
		bvg = ps_lstavg(*b, len);
		if ((*b)->n && (long)((*b)->v) < bvg)
			ps_rot(b, 'b');
		else if ((*b)->n && (long)((*b)->v) < (long)((*b)->n->v))
			ps_swap(b, 'b');
		else if ((*b)->n && (long)(ft_lstlast(*b)->v) > (long)((*b)->v))
			ps_rrot(b, 'b');
		else if (*b && (long)((*b)->v) > (long)(*a)->v)
		{
			ps_push(b, a, 'b');
			ps_swap(b, 'b');
		}
		else
			ps_push(a, b, 'b');
	}
}

int		magic(int avg, int min, int div)
{
	return (((avg - min) / div) + min);
}

int	ps_get_div(int len)
{
	int	cur;
	int	ret;

	cur = DIVISOR;
	ret = 1;
	while (cur < len)
	{
		cur *= 2;
		ret++;
	}
	return (ret);
}

/* Find the shortest way to get a number from A less then val */
int	ps_calc_next(t_list **a, int val, int len)
{
	t_list	*tmp;
	size_t	i;
	size_t	j;
	size_t	cur;

	i = 0;
	tmp = *a;
	while (((long)(tmp->v)) > val)
	{
		tmp = (tmp->n);
		i++;
	}
	j = 0;
	cur = 0;
	tmp = *a;
	while (tmp)
	{
		if (((long)(tmp->v)) > val)
			j = cur;
		tmp = (tmp->n);
		cur++;
	}
	if ((len - j) < i)
		return (1);
	return (0);
}

/* Not working as intended */
void	ps_push_next(t_list **a, int val, int move)
{
	(void)(move);
	/*
	if (move == 1)
	{
		while (*a && (*a)->n && ((long)(ft_lstlast(*a)->v)) >= val)
			ps_rrot(a, 'a');
		ps_rrot(a, 'a');
	}
	else
	{*/
	while (*a && (*a)->n && (long)((*a)->v) >= val)
		ps_rot(a, 'a');
}

/* Sort B as you go */
void	step_2(t_list **a, t_list **b, int avg)
{
	(void)(a);
	if (!*b || !(*b)->n)
		return ;
	if (((long)(*b)->v) < avg)
		ps_rot(b, 'b');
	if (((long)(*b)->v) < ((long)(*b)->n->v))
		ps_swap(b, 'b');
}

/* Push the minium number less then val possible */
void	step_1(t_list **a, t_list **b, int val, int len)
{	
	(void)(len);
	if ((long)(*a)->v < val && (long)(*a)->v > (long)(ft_lstlast(*a)->v))
		ps_rrot(a, 'a');
	if ((long)(*a)->v < val && (long)(*a)->v > (long)(*a)->n->v)
		ps_swap(a, 'a');
	if (((long)(*a)->v) < val)
		ps_push(b, a, 'b');
	else
		ps_push_next(a, val, ps_calc_next(a, val, len));
}

void	ps_sort(t_list **a, t_list **b)
{
	int	avg;
	int	len;
	
	(void)(b);
	avg = 0;
	len = ft_lstsize(*a);
	while (*a && len > 3)
	{
		if (len < DIVISOR)
			avg = ps_lstavg(*a, len);
		else
			avg = magic(ps_lstavg(*a, len), ps_lstmin(*a), ps_get_div(len));
		step_1(a, b, avg, len);
		avg = ps_lstavg(*b, DIVISOR);
		step_2(a, b, avg);
		len = ft_lstsize(*a);
	}
	ps_osort3(a, b);
	ps_step_3(a, b, ft_lstsize(*b));
}
