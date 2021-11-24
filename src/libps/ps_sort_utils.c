/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:55:44 by rafernan          #+#    #+#             */
/*   Updated: 2021/11/24 12:40:19 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

int	ps_nmax(int avg, int min, int div)
{
	return (((avg - min) / div) + min);
}

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

int	ps_calcd(size_t len)
{
	size_t	cur;
	int		ret;

	cur = PS_BLOCK;
	ret = 1;
	while (cur < len)
	{
		cur *= 2;
		ret++;
	}
	return (ret);
}
