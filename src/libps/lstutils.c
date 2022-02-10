/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 22:25:13 by rafernan          #+#    #+#             */
/*   Updated: 2022/01/20 22:25:13 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

int	ps_lstfind(t_stack *stack, int nbr)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		if ((int)(long)(tmp->v) == nbr)
			return (1);
		tmp = (tmp->n);
	}
	return (0);
}

int	ps_issorted(t_stack *a)
{
	t_stack	*tmp;
	int		count;

	if (!a)
		return (-1);
	tmp = a;
	count = 1;
	while (tmp->n)
	{
		if ((long)(tmp->v) > (long)(tmp->n->v))
			return (count);
		count++;
		tmp = (tmp->n);
	}
	return (0);
}

int	ps_lstavg(t_stack *s, size_t	len)
{
	t_stack	*tmp;
	double	n;
	double	d;

	if (!s)
		return (0);
	tmp = (s->n);
	n = (int)(long)(s->v);
	d = 1;
	while (tmp && len)
	{
		n = (d * n) + (int)(long)(tmp->v);
		n /= ++d;
		tmp = (tmp->n);
		len--;
	}
	return ((int)n);
}

int	ps_lstmin(t_list *a)
{
	int		min;
	t_list	*tmp;

	tmp = a;
	min = INT_MAX;
	while (tmp)
	{
		if (min > (int)(long)((tmp)->v))
			min = (int)(long)((tmp)->v);
		tmp = (tmp->n);
	}
	return (min);
}
