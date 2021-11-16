/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstavg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 13:51:59 by rafernan          #+#    #+#             */
/*   Updated: 2021/11/16 12:07:54 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

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
