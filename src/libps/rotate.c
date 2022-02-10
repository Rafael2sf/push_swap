/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:17:52 by rafernan          #+#    #+#             */
/*   Updated: 2022/02/09 10:33:58 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	ra(t_stack **a, t_stack **b, int print)
{
	t_stack	*ptr;
	t_stack	*tmp;

	if (!a || !*a || !((*a)->n))
		return ;
	(void)(b);
	ptr = (*a);
	(*a) = ((*a)->n);
	tmp = (*a);
	while ((tmp->n) != NULL)
		tmp = (tmp->n);
	(tmp->n) = ptr;
	(ptr->n) = NULL;
	if (print)
		write(STDOUT_FILENO, "ra\n", 3);
}

void	rb(t_stack **a, t_stack **b, int print)
{
	t_stack	*ptr;
	t_stack	*tmp;

	if (!b || !*b || !((*b)->n))
		return ;
	(void)(a);
	ptr = (*b);
	(*b) = ((*b)->n);
	tmp = (*b);
	while ((tmp->n) != NULL)
		tmp = (tmp->n);
	(tmp->n) = ptr;
	(ptr->n) = NULL;
	if (print)
		write(STDOUT_FILENO, "rb\n", 3);
}

void	rra(t_stack **a, t_stack **b, int print)
{
	t_stack	*tmp;

	if (!a || !*a || !((*a)->n))
		return ;
	(void)(b);
	tmp = (*a);
	while (tmp->n->n)
		tmp = (tmp->n);
	(tmp->n->n) = (*a);
	(*a) = (tmp->n);
	(tmp->n) = NULL;
	if (print)
		write(STDOUT_FILENO, "rra\n", 4);
}

void	rrb(t_stack **a, t_stack **b, int print)
{
	t_stack	*tmp;

	if (!b || !*b || !((*b)->n))
		return ;
	(void)(a);
	tmp = (*b);
	while (tmp->n->n)
		tmp = (tmp->n);
	(tmp->n->n) = (*b);
	(*b) = (tmp->n);
	(tmp->n) = NULL;
	if (print)
		write(STDOUT_FILENO, "rrb\n", 4);
}
