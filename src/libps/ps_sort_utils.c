/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:55:44 by rafernan          #+#    #+#             */
/*   Updated: 2021/11/23 12:02:14 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

int		ps_magic(int avg, int min, int div)
{
	return (((avg - min) / div) + min);
}

int		ps_calcd(size_t len)
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
