/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 11:03:46 by rafernan          #+#    #+#             */
/*   Updated: 2021/11/25 11:58:22 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

static int	ps_lowest2(t_list *a)
{
	t_list	*tmp;
	int		min;
	int		n;

	tmp = a;
	n = INT_MAX;
	min = ps_lstmin(a);
	while (tmp)
	{
		if ((long)(tmp->v) < n && (long)(tmp->v) != min)
			n = (long)(tmp->v);
		tmp = (tmp->n);
	}
	return (n);
}

void	push_swap(t_list **a, t_list **b, size_t len)
{
	if (!*a || len <= 0)
		ps_exit(a, 2);
	if (len == 1 || ps_issorted(*a) == 0)
		return ;
	if (len <= 3)
		return (ps_osort3(a, b));
	else if (len <= 5)
		return (ps_osort5(a, b, ft_lstsize(*a), ps_lowest2(*a)));
	else
		ps_sort(a, b);
}
