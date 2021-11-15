/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstavg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 13:51:59 by rafernan          #+#    #+#             */
/*   Updated: 2021/11/15 14:12:12 by rafernan         ###   ########.fr       */
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
	tmp = (s->next);
	n = (int)(long)(s->content);
	d = 1;
	while (tmp && len)
	{
		n = (d * n) + (int)(long)(tmp->content);
		n /= ++d;
		tmp = (tmp->next);
		len--;
	}
	return ((int)n);
}
