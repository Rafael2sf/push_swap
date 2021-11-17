/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstavg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 13:51:59 by rafernan          #+#    #+#             */
/*   Updated: 2021/11/17 15:38:29 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

int		ps_lstmin(t_list *a)
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

int	ps_lstavg(t_list *s, size_t	len)
{
	t_list	*tmp;
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
