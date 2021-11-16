/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 21:17:03 by rafernan          #+#    #+#             */
/*   Updated: 2021/11/16 12:07:54 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

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
	/*	
	if (ab == 'b')
		ps_prints(NULL, *s);
	else
		ps_prints(*s, NULL);
	usleep(12300);*/
}
