/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 22:10:26 by rafernan          #+#    #+#             */
/*   Updated: 2021/11/11 16:07:54 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	show_stacks(t_list *a, t_list *b)
{
	ft_lstiter(a, ps_putvl);
	ft_putchar(1, '\n');
	ft_lstiter(b, ps_putvl);
	ft_putstr(1, "\n");
}

// lol
void	ps_alg1(t_list **a, t_list **b)
{
	int		n;

	while ((*a) != NULL)
	{
		if (!*b || ((int)(*a)->content) > ((int)(*b)->content))
		{
			n = ps_issorted(*a);
			if (n == 0)
				break ;
			while (n--)
				ps_push(b, a, 'b');
		}
		else
		{
			ps_push(a, b, 'a');
			ps_swap(a, 'a');
		}
	}
	while (*b)
		ps_push(a, b, 'a');
}

int		ps_lstavg(t_list *a)
{
	long	avg;
	float	i;
	t_list	*tmp;

	i = 0;
	tmp = a;
	avg = 0;
	while (tmp)
	{
		avg += (long)(tmp->content);
		i += 1;
		tmp = (tmp->next);
	}
	return (avg / i);
}
