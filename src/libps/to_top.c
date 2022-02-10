/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_top.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:40:09 by rafernan          #+#    #+#             */
/*   Updated: 2022/01/21 11:40:09 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

static size_t	ps_calc_ra(t_stack *a, char sign, int val);
static size_t	ps_calc_rra(t_stack *a, char sign, int val);

void	ps_to_top(t_stack **a, char sign, int val)
{
	size_t	ra_count;
	size_t	rra_count;

	ra_count = ps_calc_ra(*a, sign, val);
	rra_count = ps_calc_rra(*a, sign, val);
	if (ra_count <= rra_count)
	{
		while (*a && (*a)->n && ra_count--)
			ps_do(a, NULL, ra);
	}
	else
	{
		while (*a && (*a)->n && rra_count--)
			ps_do(a, NULL, rra);
	}
}

static size_t	ps_calc_ra(t_stack *a, char sign, int val)
{
	t_stack	*tmp;
	size_t	i;

	i = 0;
	tmp = a;
	while (tmp)
	{
		if (sign == '>' && ((long)(tmp->v)) > val)
			break ;
		else if (sign == '<' && ((long)(tmp->v)) < val)
			break ;
		tmp = (tmp->n);
		i++;
	}
	return (i);
}

static size_t	ps_calc_rra(t_stack *a, char sign, int val)
{
	t_stack	*tmp;
	size_t	cur;
	size_t	i;

	i = 0;
	cur = 0;
	tmp = a;
	while (tmp)
	{
		if (sign == '>' && ((long)(tmp->v)) > val)
			cur = i;
		else if (sign == '<' && ((long)(tmp->v)) < val)
			cur = i;
		tmp = (tmp->n);
		i++;
	}
	return (i - cur);
}
