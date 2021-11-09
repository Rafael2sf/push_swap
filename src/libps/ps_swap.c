/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 20:23:35 by rafernan          #+#    #+#             */
/*   Updated: 2021/11/09 15:55:13 by rafernan         ###   ########.fr       */
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
}	
