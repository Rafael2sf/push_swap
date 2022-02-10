/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:30:12 by rafernan          #+#    #+#             */
/*   Updated: 2022/01/21 11:30:12 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	ps_do(t_stack **a, t_stack **b, void (*f)(t_stack**, t_stack**, int))
{
	if (!f)
		return ;
	f(a, b, 1);
}

int	ps_at(t_stack *s, int loc)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	if (!s || loc < -1)
		return (-1);
	tmp = s;
	if (loc == -1)
	{
		while (tmp->n)
			tmp = (tmp->n);
	}
	else
	{
		while (tmp && i != loc)
		{
			tmp = (tmp->n);
			i++;
		}
		if (!tmp)
			return (-1);
	}
	return ((int)(long)(tmp->v));
}

int	ps_lstmaxp(t_stack *a, int len)
{
	t_stack	*tmp;
	int		max;
	int		cur;
	int		i;

	if (!a)
		return (0);
	tmp = a;
	max = (int)(long)((tmp)->v);
	cur = 0;
	i = 0;
	while (tmp)
	{
		if (max < (int)(long)((tmp)->v))
		{
			max = (int)(long)((tmp)->v);
			i = cur;
		}
		tmp = (tmp->n);
		cur++;
	}
	if (i > (len / 2))
		return (len - i);
	return (-i);
}
