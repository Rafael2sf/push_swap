/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:55:44 by rafernan          #+#    #+#             */
/*   Updated: 2021/11/22 12:24:37 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

int		ps_magic(int avg, int min, int div)
{
	return (((avg - min) / div) + min);
}

int		ps_calcd(void)
{
	int	cur;
	int	ret;

	cur = 5;
	ret = 1;
	while (cur < PS_BLOCK)
	{
		cur *= 2;
		ret++;
	}
	return (ret);
}
