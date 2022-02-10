/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:10:40 by rafernan          #+#    #+#             */
/*   Updated: 2022/02/03 14:01:08 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	pa(t_stack **a, t_stack **b, int print)
{
	t_stack	*tmp;

	if (!b || !*b || !a)
		return ;
	tmp = (*b);
	(*b) = ((*b)->n);
	if (a && *a)
		(tmp->n) = (*a);
	else
		(tmp->n) = NULL;
	(*a) = tmp;
	if (print)
		write(STDOUT_FILENO, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b, int print)
{
	t_stack	*tmp;

	if (!a || !*a || !b)
		return ;
	tmp = (*a);
	(*a) = ((*a)->n);
	if (b && *b)
		(tmp->n) = (*b);
	else
		(tmp->n) = NULL;
	(*b) = tmp;
	if (print)
		write(STDOUT_FILENO, "pb\n", 3);
}
