/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_opers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:40:20 by rafernan          #+#    #+#             */
/*   Updated: 2021/11/24 17:04:45 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	ps_swap(t_list **s, char ab)
{
	t_list	*tmp;

	if (ab)
		ft_printf("s%c\n", ab);
	if (!s || !(*s) || !((*s)->n))
		return ;
	tmp = ((*s)->n);
	((*s)->n) = ((*s)->n->n);
	(tmp->n) = (*s);
	(*s) = tmp;
}	

void	ps_push(t_list **a, t_list **b, char ab)
{
	t_list	*tmp;

	if (ab)
		ft_printf("p%c\n", ab);
	if (!b || !*b)
		return ;
	tmp = (*b);
	(*b) = ((*b)->n);
	if (a && *a)
		(tmp->n) = (*a);
	else
		(tmp->n) = NULL;
	(*a) = tmp;
	tmp = NULL;
}

void	ps_rot(t_list **s, char ab)
{
	t_list	*ptr;
	t_list	*tmp;

	if (ab)
		ft_printf("r%c\n", ab);
	if (!s || !*s || !((*s)->n))
		return ;
	ptr = (*s);
	(*s) = ((*s)->n);
	tmp = (*s);
	while ((tmp->n) != NULL)
		tmp = (tmp->n);
	(tmp->n) = ptr;
	(ptr->n) = NULL;
}

void	ps_rrot(t_list **s, char ab)
{
	t_list	*tmp;

	if (ab)
		ft_printf("rr%c\n", ab);
	if (!s || !*s || !((*s)->n))
		return ;
	tmp = (*s);
	while (tmp->n->n)
		tmp = (tmp->n);
	(tmp->n->n) = (*s);
	(*s) = (tmp->n);
	(tmp->n) = NULL;
}
