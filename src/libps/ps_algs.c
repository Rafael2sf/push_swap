/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_alg1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 22:10:26 by rafernan          #+#    #+#             */
/*   Updated: 2021/11/07 22:56:09 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

// HELP ME
void	ps_alg1(t_list **a, t_list **b)
{
	ps_push(b, a, 'b');
	while ((*a) != NULL)
	{
		if (!*b || ((*a)->content) > ((*b)->content))
			ps_push(b, a, 'a');
		else
		{
			ps_push(a, b, 'a');
			ps_swap(a, 'a');
		}
		/*
		ft_lstiter(*a, ps_show);
		ft_putchar(1, '\n');
		ft_lstiter(*b, ps_show);
		ft_putstr(1, "\n\n");
		*/
	}
	while (*b)
		ps_push(a, b, 'b');
}
