/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:13:10 by rafernan          #+#    #+#             */
/*   Updated: 2022/02/03 14:27:24 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	sa(t_stack **a, t_stack **b, int print)
{
	t_stack	*tmp;

	if (!a || !(*a) || !((*a)->n))
		return ;
	(void)(b);
	tmp = ((*a)->n);
	((*a)->n) = ((*a)->n->n);
	(tmp->n) = (*a);
	(*a) = tmp;
	if (print)
		write(STDOUT_FILENO, "sa\n", 3);
}

void	sb(t_stack **a, t_stack **b, int print)
{
	t_stack	*tmp;

	if (!b || !(*b) || !((*b)->n))
		return ;
	(void)(a);
	tmp = ((*b)->n);
	((*b)->n) = ((*b)->n->n);
	(tmp->n) = (*b);
	(*b) = tmp;
	if (print)
		write(STDOUT_FILENO, "sb\n", 3);
}
