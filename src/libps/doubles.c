/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_opers2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 23:07:35 by rafernan          #+#    #+#             */
/*   Updated: 2022/01/20 23:07:35 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	ss(t_stack **a, t_stack **b, int print)
{
	(void)(print);
	sa(a, b, 0);
	sb(a, b, 0);
	write(STDOUT_FILENO, "ss\n", 3);
}

void	rr(t_stack **a, t_stack **b, int print)
{
	(void)(print);
	ra(a, b, 0);
	rb(a, b, 0);
	write(STDOUT_FILENO, "rr\n", 3);
}

void	rrr(t_stack **a, t_stack **b, int print)
{
	(void)(print);
	rra(a, b, 0);
	rrb(a, b, 0);
	write(STDOUT_FILENO, "rrr\n", 4);
}
