/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_app.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:46:26 by rafernan          #+#    #+#             */
/*   Updated: 2021/11/23 16:56:37 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "libps.h"

void	ps_prints(t_list *a, t_list *b)
{
	t_list	*ptr_a;
	t_list	*ptr_b;

	ptr_a = a;
	ptr_b = b;

	ft_putstr(1, "A: \t");
	if (!ptr_a)
		ft_putstr(1, " ... ");
	while (ptr_a)
	{
		ft_putnbr(1, (long)(ptr_a->v));
		ft_putchar(1, ' ');
		ptr_a = (ptr_a->n);
	}
	ft_putstr(1, "\nB:\t");
	if (!ptr_b)
		ft_putstr(1, " ... ");
	while (ptr_b)
	{
		ft_putnbr(1, (long)(ptr_b->v));
		ft_putchar(1, ' ');
		ptr_b = (ptr_b->n);
	}
	ft_putchar(1, '\n');
}

void	app(t_list **a, t_list **b)
{
	char	*inpt;
	
	while (1)
	{
		inpt = get_next_line(0);
		if (ft_strncmp("sa", inpt, 2) == 0)
			ps_swap(a, '\0');
		else if (ft_strncmp("sb", inpt, 2) == 0)
			ps_swap(b, '\0');
		else if (ft_strncmp("ss", inpt, 2) == 0)
		{
			ps_swap(a, '\0');
			ps_swap(b, '\0');
		}
		else if (ft_strncmp("rra", inpt, 3) == 0)
			ps_rrot(a, '\0');
		else if (ft_strncmp("rrb", inpt, 3) == 0)
			ps_rrot(b, '\0');
		else if (ft_strncmp("rrr", inpt, 3) == 0)
		{
			ps_rrot(a, '\0');
			ps_rrot(b, '\0');
		}
		else if (ft_strncmp("pa", inpt, 2) == 0)
			ps_push(a, b, '\0');
		else if (ft_strncmp("pb", inpt, 2) == 0)
			ps_push(b, a, '\0');
		else if (ft_strncmp("ra", inpt, 2) == 0)
			ps_rot(a, '\0');
		else if (ft_strncmp("rb", inpt, 2) == 0)
			ps_rot(b, '\0');
		else if (ft_strncmp("rr", inpt, 2) == 0)
		{
			ps_rot(a, '\0');
			ps_rot(b, '\0');
		}
		else if (ft_strncmp("q", inpt, 1) == 0)
		{
			ft_lstclear(b, NULL);
			free(inpt);
			return ;
		}
		if (inpt)
			free(inpt);
		inpt = NULL;
		ps_prints(*a, *b);
	}
}
*/