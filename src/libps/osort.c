/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   osort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 22:56:31 by rafernan          #+#    #+#             */
/*   Updated: 2022/01/20 22:56:31 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	ps_osort3(t_stack **s)
{
	if (ps_at(*s, 0) < ps_at(*s, 1) && ps_at(*s, 1) > ps_at(*s, 2))
		ps_do(s, NULL, rra);
	else if (ps_at(*s, 0) > ps_at(*s, 2))
		ps_do(s, NULL, ra);
	if (ps_at(*s, 0) > ps_at(*s, 1))
		ps_do(s, NULL, sa);
}

void	ps_osort5(t_stack **a, t_stack **b, int len)
{
	int	avg;

	avg = ps_lstavg(*a, len);
	ps_to_top(a, '<', avg);
	ps_do(a, b, pb);
	if (len == 5)
	{
		ps_to_top(a, '<', avg);
		ps_do(a, b, pb);
	}
	ps_osort3(a);
	ps_do(a, b, pa);
	if (len == 5)
		ps_do(a, b, pa);
	if (ps_at(*a, 0) > ps_at(*a, 1))
		ps_do(a, NULL, sa);
}
