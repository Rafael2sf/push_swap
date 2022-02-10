/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_group.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:55:33 by rafernan          #+#    #+#             */
/*   Updated: 2022/02/09 10:58:26 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

static int	ps_calcd(size_t len);

int	ps_getgroup(t_stack *a, int len)
{
	int	min;
	
	min = ps_lstmin(a);
	return (((ps_lstavg(a, len) - min) / ps_calcd(len)) + min);
}

static int	ps_calcd(size_t len)
{
	size_t	cur;
	int		ret;

	cur = PS_GROUP;
	ret = 1;
	while (cur < len)
	{
		cur *= 2;
		ret++;
	}
	return (ret);
}
