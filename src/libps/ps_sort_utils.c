/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:55:44 by rafernan          #+#    #+#             */
/*   Updated: 2021/11/17 17:20:36 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

int		ps_block(int avg, int min, int div)
{
	return (((avg - min) / div) + min);
}

int		ps_div(int len)
{
	int	cur;
	int	ret;

	cur = DIVISOR;
	ret = 1;
	while (cur < len)
	{
		cur *= 2;
		ret++;
	}
	return (ret);
}
