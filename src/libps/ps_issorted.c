/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_issorted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 21:50:15 by rafernan          #+#    #+#             */
/*   Updated: 2021/11/07 21:57:27 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

int	ps_issorted(t_list	*a)
{
	t_list	*tmp;

	if (!a)
		return (-1);
	tmp = a;
	while (tmp->next)
	{
		if ((long)(tmp->content) > (long)(tmp->next->content))
			return (0);
		tmp = (tmp->next);
	}
	return (1);
}
