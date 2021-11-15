/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 21:00:20 by rafernan          #+#    #+#             */
/*   Updated: 2021/11/15 14:11:57 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	ps_push(t_list **a, t_list **b, char ab)
{
	t_list	*tmp;

	if (ab)
		ft_printf("p%c\n", ab);
	if (!b || !*b)
		return ;
	tmp = (*b);
	(*b) = ((*b)->next);
	if (a && *a)
		(tmp->next) = (*a);
	else
		(tmp->next) = NULL;
	(*a) = tmp;
	tmp = NULL;
	/*	
	if (ab == 'b')
		ps_prints(*b, *a);
	else
		ps_prints(*a, *b);
	usleep(12300);
*/
}
