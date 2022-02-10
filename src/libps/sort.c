/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:31:17 by rafernan          #+#    #+#             */
/*   Updated: 2022/01/21 12:31:17 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

static void	ps_sort100_to_b(t_list **a, t_list **b, int avg);
static void	ps_sort100_to_a(t_list **a, t_list **b);

void	ps_sort100(t_list **a, t_list **b, int len)
{
	int	avg;

	while (len >= 3)
	{
		avg = ps_getgroup(*a, len);
		ps_sort100_to_b(a, b, avg);
		len--;
	}
	len = ft_lstsize(*b);
	if (ps_at(*a, 0) > ps_at(*a, 1))
		ps_do(a, b, sa);
	while (len > 1)
	{
		ps_sort100_to_a(a, b);
		len--;
	}
	ps_do(a, b, pa);
	if (ps_at(*a, 0) > ps_at(*a, 1))
		ps_do(a, b, sa);
}

static void	ps_sort100_to_b(t_list **a, t_list **b, int avg)
{
	if (ps_at(*a, 0) >= avg)
	{
		ps_to_top(a, '<', avg);
	}
	ps_do(a, b, pb);
	if (!*b || !(*b)->n)
		return ;
	if ((*b)->n->n && ps_at(*b, 0) < ps_at(*b, 2))
		ps_do(a, b, rb);
	if (ps_at(*b, 0) < ps_at(*b, 1))
	{
		if (ps_at(*a, 0) < ps_at(*a, 1))
			ps_do(a, b, ss);
		else
			ps_do(a, b, sb);
	}
}

static void	ps_sort100_to_a(t_list **a, t_list **b)
{
	ssize_t	maxp;

	maxp = ps_lstmaxp(*b, ft_lstsize(*b));
	if (maxp == -1)
		ps_do(a, b, sb);
	else
	{
		while (maxp > 0)
		{
			ps_do(a, b, rrb);
			maxp--;
		}
		while (maxp < 0)
		{
			ps_do(a, b, rb);
			maxp++;
		}
	}
	ps_do(a, b, pa);
	if (ps_at(*a, 0) > ps_at(*a, 1))
		ps_do(a, b, sa);
}

/*
static void	divide(t_stack **a, t_stack **b, int len)
{
	int	avg;
	int	n;

	n = 0;
	while (len - n != 3)
	{
		avg = ps_lstavg(*a, len - n + 1);
		ps_to_top(a, '<', avg);
		ps_do(a, b, pb);
		n++;
	}
}

void	ps_sort100(t_stack **a, t_stack **b, int len)
{
		divide(a, b, len);
		ps_osort3(a);
		show(*a, *b);
}
*/
