/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstatoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 00:33:07 by rafernan          #+#    #+#             */
/*   Updated: 2021/11/17 15:30:34 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libps.h"

t_list	*ps_lstatoi(char **list, int size)
{
	t_list	*stack;
	t_list	*tmp;
	int		i;
	int		nbr;

	if (size <= 0 || !list)
		return (NULL);
	if (!ps_atoi(*list, &nbr))
		return (NULL);
	tmp = ft_lstnew((void *)(long)(nbr));
	if (!tmp)
		return (NULL);
	stack = tmp;
	i = 0;
	while (++i < size)
	{
		if (!ps_atoi(*(list + i), &nbr) || ps_lstfind(stack, nbr))
			ps_exit(&stack, 3);
		(tmp->n) = ft_lstnew((void *)(long)(nbr));
		if (!tmp->n)
			ps_exit(&stack, 3);
		tmp = (tmp->n);
	}
	return (stack);
}
