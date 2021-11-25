/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:41:42 by rafernan          #+#    #+#             */
/*   Updated: 2021/11/25 11:58:33 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

int	ps_lstfind(t_list *s, int nbr)
{
	t_list	*tmp;

	tmp = s;
	while (tmp)
	{
		if ((long)(tmp->v) == nbr)
			return (1);
		tmp = (tmp->n);
	}
	return (0);
}

int	ps_lstmin(t_list *a)
{
	int		min;
	t_list	*tmp;

	tmp = a;
	min = INT_MAX;
	while (tmp)
	{
		if (min > (int)(long)((tmp)->v))
			min = (int)(long)((tmp)->v);
		tmp = (tmp->n);
	}
	return (min);
}

int	ps_lstavg(t_list *s, size_t	len)
{
	t_list	*tmp;
	double	n;
	double	d;

	if (!s)
		return (0);
	tmp = (s->n);
	n = (int)(long)(s->v);
	d = 1;
	while (tmp && len)
	{
		n = (d * n) + (int)(long)(tmp->v);
		n /= ++d;
		tmp = (tmp->n);
		len--;
	}
	return ((int)n);
}

t_list	*ps_lstatoi(char **list, int size)
{
	t_list	*stack;
	t_list	*tmp;
	int		i;
	int		nbr;

	if (size <= 0 || !list || !*(*list))
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
		if (!*(list[i]) || !ps_atoi(*(list + i), &nbr)
			|| ps_lstfind(stack, nbr))
			ps_exit(&stack, 3);
		(tmp->n) = ft_lstnew((void *)(long)(nbr));
		if (!tmp->n)
			ps_exit(&stack, 3);
		tmp = (tmp->n);
	}
	return (stack);
}
