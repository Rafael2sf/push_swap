/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 21:24:23 by rafernan          #+#    #+#             */
/*   Updated: 2021/11/07 21:32:20 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	ps_rrot(t_list **s, char ab)
{
	t_list	*tmp;

	if (ab)
		ft_printf("rr%c\n", ab);
	if (!s || !*s || !((*s)->next))
		return ;
	tmp = (*s);
	while (tmp->next->next)
		tmp = (tmp->next);
	(tmp->next->next) = (*s);
	(*s) = (tmp->next);
	(tmp->next) = NULL;
	/*		
	if (ab == 'b')
		ps_prints(NULL, *s);
	else
		ps_prints(*s, NULL);
	ps_prints(*s, NULL);
	usleep(12300);
*/
}
