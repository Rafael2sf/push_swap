/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 20:23:35 by rafernan          #+#    #+#             */
/*   Updated: 2021/11/15 14:11:34 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	ps_swap(t_list **s, char ab)
{
	t_list	*tmp;

	if (ab)
		ft_printf("s%c\n", ab);
	if (!s || !(*s) || !((*s)->next))
		return ;
	tmp = ((*s)->next);
	((*s)->next) = ((*s)->next->next);
	(tmp->next) = (*s);
	(*s) = tmp;
	/*	
	if (ab == 'a')
		ps_prints(*s, NULL);
	else
		ps_prints(NULL, *s);
	usleep(12300);
	*/
}	
