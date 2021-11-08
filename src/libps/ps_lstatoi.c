/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstatoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 00:33:07 by rafernan          #+#    #+#             */
/*   Updated: 2021/11/08 16:01:42 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libps.h"

// Not cheking for input bigger then int and if number already exist
t_list	*ps_lstatoi(char **list, int size)
{
	t_list	*stack;
	t_list	*tmp;
	int		i;

	if (size <= 0 || !list)
		return (NULL);
	tmp = ft_lstnew((void *)(long)ft_atoi(*list));
	if (!tmp || ((long)(tmp->content) == 0 && **list != '0'))
		ps_exit(&stack, 1);
	stack = tmp;
	i = 0;
	while (++i < size)
	{
		(tmp->next) = ft_lstnew((void *)(long)ft_atoi(*(list + i)));
		if (!tmp->next
			|| ((long)(tmp->next->content) == 0 && **(list + i) != '0'))
			ps_exit(&stack, 1);
		tmp = (tmp->next);
	}
	return (stack);
}
