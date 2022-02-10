/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 22:10:35 by rafernan          #+#    #+#             */
/*   Updated: 2022/01/20 22:10:35 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

static void	ps_exit(t_stack **stack, int ret);

t_stack	*ps_to_stack(char **argv, unsigned int size)
{
	t_stack			*tmp;
	t_stack			*stack;
	unsigned int	i;
	int				nbr;

	if (size == 0 || !argv || !*(*argv))
		return (NULL);
	if (!ps_atoi_l(*argv, &nbr))
		return (NULL);
	tmp = ft_lstnew((void *)(long)(nbr));
	if (!tmp)
		return (NULL);
	stack = tmp;
	i = 0;
	while (++i < size)
	{
		if (!*(argv[i]) || !ps_atoi_l(*(argv + i), &nbr)
			|| ps_lstfind(stack, nbr))
			ps_exit(&stack, 3);
		(tmp->n) = ft_lstnew((void *)(long)(nbr));
		if (!tmp->n)
			ps_exit(&stack, 3);
		tmp = (tmp->n);
	}
	return (stack);
}

static void	ps_exit(t_stack **stack, int ret)
{
	ft_lstclear(stack, NULL);
	ft_putstr(STDERR_FILENO, "Error\n");
	exit(ret);
}
