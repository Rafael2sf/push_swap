/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_issorted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 21:50:15 by rafernan          #+#    #+#             */
/*   Updated: 2021/11/11 15:33:07 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

int	ps_issorted(t_list	*a)
{
	t_list	*tmp;
	int		count;

	if (!a)
		return (-1);
	tmp = a;
	count = 1;
	while (tmp->next)
	{
		if ((long)(tmp->content) > (long)(tmp->next->content))
			return (count);
		count++;
		tmp = (tmp->next);
	}
	return (0);
}
