/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_get_next.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:52:05 by rafernan          #+#    #+#             */
/*   Updated: 2021/11/17 17:20:34 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

/* NOT WORKING TO DO */

/* Find the shortest way to get a number from A less then val */
int	ps_calc_next(t_list **a, int val, int len)
{
	t_list	*tmp;
	size_t	i;
	size_t	j;
	size_t	cur;

	i = 0;
	tmp = *a;
	while (((long)(tmp->v)) > val)
	{
		tmp = (tmp->n);
		i++;
	}
	j = 0;
	cur = 0;
	tmp = *a;
	while (tmp)
	{
		if (((long)(tmp->v)) > val)
			j = cur;
		tmp = (tmp->n);
		cur++;
	}
	if ((len - j) < i)
		return (1);
	return (0);
}

/* Not working as intended */
void	ps_push_next(t_list **a, int val, int move)
{
	(void)(move);
	/*
	if (move == 1)
	{
		while (*a && (*a)->n && ((long)(ft_lstlast(*a)->v)) >= val)
			ps_rrot(a, 'a');
		ps_rrot(a, 'a');
	}
	else
	{*/
	while (*a && (*a)->n && (long)((*a)->v) >= val)
		ps_rot(a, 'a');
}
