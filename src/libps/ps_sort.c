/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:00:46 by rafernan          #+#    #+#             */
/*   Updated: 2021/11/15 17:35:07 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"
#include <stdio.h>

#define MAGIC_NUMBER 7

static void	step_1(t_list **a, t_list **b);

/* Somewhat sort next magic digits */
void	step_4(t_list **a, t_list **b, size_t count)
{
	int	bvg;
	
	bvg = ps_lstavg(*b, count);
	while (*b && ((long)ft_lstlast(*b)->content) > bvg)
		ps_rot(b, 'b');	
	while (*b && count)
	{
		if (((long)ft_lstlast(*b)->content) > ((long)(*b)->content))
			ps_rrot(b, 'b');
		else if (((*b)->next) && ((long)(*b)->next->content) > ((long)(*b)->content))
			ps_swap(b, 'b');
		else if (((long)(*b)->content) < bvg)
		{
			if (((*b)->next) && ((long)(*b)->next->content) < bvg)
				ps_push(a, b, 'a');
			else
				ps_rot(b, 'b');
			count--;
		}
		else if ((long)((*b)->content) > (long)((*a)->content))
			ps_rot(a, 'a');
		else
		{
			ps_push(a, b, 'a');
			count--;
		}
	}
}

/* Sort the last numbers */
void	step_3(t_list **a, t_list **b, size_t count)
{
	int bvg;

	while (*b && count)
	{	
		bvg = ps_lstavg(*b, ft_lstsize(*b));
		if ((*b)->next && (long)((*b)->content) < bvg)
			ps_rot(b, 'b');	
		else if ((*b)->next && (long)((*b)->content) < (long)((*b)->next->content))
			ps_swap(b, 'b');
		else if ((long)(ft_lstlast(*b)->content) > (long)((*b)->content))
			ps_rrot(b, 'b');
		else if ((long)(ft_lstlast(*a)->content) < (long)((*a)->content))
			ps_rrot(a, 'a');
		else if ((long)((*b)->content) < (long)((*a)->content))
		{
			if (((long)(ft_lstlast(*a)->content)) > ((long)((*b)->content)))
				ps_rrot(a, 'a');
			ps_push(a, b, 'a');
			count--;
		}
		else
		{
			ps_push(b, a, 'b');
			ps_swap(b, 'b');
			count++;
		}
	}
}

/* Somewhat sort b numbers as step 1 goes */
void	step_2(t_list **a, t_list **b)
{
	int	bvg;
	
	if (!*b || !(*b)->next || ps_issorted(*a) == 0)
		return (step_1(a, b));
	while (*b)
	{
		bvg = ps_lstavg(*b, ft_lstsize(*b));
		if ((long)((*b)->content) < bvg)
			ps_rot(b, 'b');
		else if ((long)((*b)->content) < (long)((*b)->next->content))
			ps_swap(b, 'b');
		else if ((long)((*b)->content) < (long)(ft_lstlast(*b)->content))
			ps_rrot(b, 'b');
		else
			return (step_2(a, b));
	}
}

/* Push numbers less then avg, lowest first, from possible moves */
void	step_1(t_list **a, t_list **b)
{
	int	avg;

	avg = ft_lstsize(*a);
	if (avg <= 2 || ps_issorted(*a) == 0)
		return ;
	avg = ps_lstavg(*a, avg);
	if ((long)((*a)->content) < avg)
	{
		if ((long)((*a)->content) > (long)(ft_lstlast(*a)->content))
			ps_rrot(a, 'a');
		if ((long)((*a)->content) > (long)((*a)->next->content))
			ps_swap(a, 'a');	
		ps_push(b, a, 'b');
	}
	else if ((long)((*a)->next->content) < avg)
		ps_swap(a, 'a');
	else if (((long)(ft_lstlast(*a)->content) < avg))
		ps_rrot(a, 'a');
	else
		ps_rot(a, 'a');
	step_1(a, b);
}

void	ps_sort(t_list	**a, t_list **b, int alen, int blen)
{
	int	count;
	
	(void)(alen);
	(void)(blen);
	step_1(a, b);
	blen = ft_lstsize(*b);
	if ((long)((*a)->content) > (long)((*a)->next->content))
		ps_swap(a, 'a');
	if (blen > ((MAGIC_NUMBER * MAGIC_NUMBER)))
		count = (blen / MAGIC_NUMBER) / 2;
	else
		count = MAGIC_NUMBER;
	step_3(a, b, count);
	step_4(a, b, count);
	step_3(a, b, count);
	//app(a, b);
}

/*
void	ps_asort_3(t_list *a)
{
	
}*/