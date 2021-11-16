/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 20:23:35 by rafernan          #+#    #+#             */
/*   Updated: 2021/11/16 12:13:09 by rafernan         ###   ########.fr       */
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
	/*	
	if (ab == 'a')
		ps_prints(*s, NULL);
	else
		ps_prints(NULL, *s);
	usleep(12300);
	*/
}	
