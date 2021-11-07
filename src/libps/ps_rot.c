/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 21:17:03 by rafernan          #+#    #+#             */
/*   Updated: 2021/11/07 22:49:37 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	ps_rot(t_list **s, char ab)
{
	t_list	*ptr;
	t_list	*tmp;
	
	ft_printf("r%c\n", ab);
	if (!s || !*s || !((*s)->next))
		return ;
	ptr = (*s);
	(*s) = ((*s)->next);
	tmp = (*s);
	while ((tmp->next) != NULL)
		tmp = (tmp->next);
	(tmp->next) = ptr;
	(ptr->next) = NULL;
}
