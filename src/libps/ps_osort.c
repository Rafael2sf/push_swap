/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_osort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:21:35 by rafernan          #+#    #+#             */
/*   Updated: 2021/11/16 10:23:21 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

/* optimized sort for list of size 3 */
void	ps_osort3(t_list **a)
{
	if (!a || !(*a)->next)
		return ;
	if (!(*a)->next->next)
	{
		if (L(*a)->content > L(*a)->next->content)
			ps_swap(a, 'a');
		return ;
	}
	if (L(*a)->content < L(*a)->next->content)
	{
		if (L(*a)->next->content > L(*a)->next->next->content)
			ps_rrot(a, 'a');
		if (L(*a)->content > L(*a)->next->content)
			ps_swap(a, 'a');
		return ;
	}
	else if (L(*a)->content > L(*a)->next->content)
	{
		if (L(*a)->content > L(*a)->next->next->content)
			ps_rot(a, 'a');
		if (L(*a)->content > L(*a)->next->content)
			ps_swap(a, 'a');
		return ;
	}
}