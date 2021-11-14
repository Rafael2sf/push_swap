/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:00:46 by rafernan          #+#    #+#             */
/*   Updated: 2021/11/13 20:49:22 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

#define MAGIC_NUMBER 11

static void	step_1(t_list **a, t_list **b);

static void	step_3(t_list **a, t_list **b, size_t count)
{
	int bvg;

	while (count && ft_lstsize(*a) < ft_lstsize(*b))
	{	
		bvg = ps_lstavg(*b, ft_lstsize(*b));
		if ((long)((*b)->content) < bvg)
			ps_rot(b, 'b');	
		else if ((long)((*b)->content) < (long)((*b)->next->content))
			ps_swap(b, 'b');
		else if ((long)(ft_lstlast(*b)->content) > (long)((*b)->content))
			ps_rrot(b, 'b');
		else if ((long)(ft_lstlast(*a)->content) < (long)((*a)->content))
			ps_rrot(a, 'a');
		else if ((long)((*b)->content) < (long)((*a)->content))
		{
			ps_push(a, b, 'a');
			count--;
		}
		else
		{
			ps_push(b, a, 'a');
			ps_swap(b, 'b');
			count++;
		}
	}
}

/* Somewhat sort b numbers as step 1 goes */
static void	step_2(t_list **a, t_list **b)
{
	int	bvg;
	
	if (!*b || !(*b)->next)
		return (step_1(a, b));
	while (1)
	{
		bvg = ps_lstavg(*b, ft_lstsize(*b));
		if ((long)((*b)->content) < (long)(ft_lstlast(*b)->content)
		|| (long)((*b)->content) < bvg)
			ps_rot(b, 'b');
		else if ((long)((*b)->content) < (long)((*b)->next->content))
			ps_swap(b, 'b');
		else
			return (step_1(a, b));
	}
}

/* Push numbers less then avg, lowest first, from possible moves */
static void	step_1(t_list **a, t_list **b)
{
	int	avg;

	avg = ft_lstsize(*a);
	if (avg <= 2)
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
	step_2(a, b);
}

void	ps_sort(t_list	**a, t_list **b, int alen, int blen)
{
	int	count;
	
	(void)(alen);
	(void)(blen);
	step_1(a, b);
	blen = ft_lstsize(*b);
	if (blen > 50)
		count = blen / MAGIC_NUMBER;
	else
		count = MAGIC_NUMBER;
	if ((long)((*a)->content) > (long)((*a)->next->content))
		ps_swap(a, 'a');
	step_3(a, b, count);
}