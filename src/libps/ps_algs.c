/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 22:10:26 by rafernan          #+#    #+#             */
/*   Updated: 2021/11/08 14:32:54 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	show_stacks(t_list *a, t_list *b)
{
	ft_lstiter(a, putlongv);
	ft_putchar(1, '\n');
	ft_lstiter(b, putlongv);
	ft_putstr(1, "\n");
}

// lol
void	ps_alg1(t_list **a, t_list **b)
{
	int		n;

	while ((*a) != NULL)
	{
		if (!*b || ((*a)->content) > ((*b)->content))
		{
			n = ps_issorted(*a);
			if (n == 0)
				break ;
			while (n--)
			{
				ps_push(b, a, 'b');
				//show_stacks(*a, *b);
			}
		}
		else
		{
			ps_push(a, b, 'a');
			ps_swap(a, 'a');
			//show_stacks(*a, *b);
		}
	}
	while (*b)
		ps_push(a, b, 'a');
}

void	ps_alg2(t_list **a, t_list **b)
{
	(void)(a);
	(void)(b);
	return ;
}
