/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:30:43 by rafernan          #+#    #+#             */
/*   Updated: 2021/11/24 11:05:42 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "./libps/libps.h"
#include "stdio.h"

static int	ps_lowest2(t_list *a)
{
	t_list	*tmp;
	int		min;
	int		n;

	tmp = a;
	n = INT_MAX;
	min = ps_lstmin(a);
	while (tmp)
	{
		if ((long)(tmp->v) < n && (long)(tmp->v) != min)
			n = (long)(tmp->v);
		tmp = (tmp->n);
	}
	return (n);
}

void	push_swap(t_list **a, t_list **b, size_t len)
{
	if (!*a || len <= 0)
		ps_exit(a, 2);
	if (len == 1 || ps_issorted(*a) == 0)
		return ;
	if (len <= 3)
		return (ps_osort3(a, b));
	else if (len <= 5)
		return (ps_osort5(a, b, ft_lstsize(*a), ps_lowest2(*a)));
	else
		ps_sort(a, b);
}

/**/

void	ps_putvl(void *x)
{
	ft_putnbr(1, (long)(x));
	ft_putchar(1, ' ');
}

void	show(t_list *a, t_list *b)
{
	ft_putchar(1, '\t');
	if (!a)
		ft_putstr(1, "(empty)");
	ft_lstiter(a, ps_putvl);
	ft_putstr(1, "\n\t");
	ft_lstiter(b, ps_putvl);
	if (!b)
		ft_putstr(1, "(empty)");
	ft_putchar(1, '\n');
}

void	status(t_list *a, t_list *b)
{
	if (ps_issorted(a) != 0)
		ft_putstr(1, "\033[31mKO\033[39m\n");
	else if (b)
		ft_putstr(1, "\033[33mKO\033[39m\n");
	else
		ft_putstr(1, "\033[32mOK\033[39m\n");
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	if (argc <= 1)
		return (1);
	a = ps_lstatoi(argv + 1, argc - 1);
	if (!a)
	{
		ft_putstr(2, "Error\n");
		exit(2);	
	}
	b = NULL;
	push_swap(&a, &b, ft_lstsize(a));
	ft_lstclear(&a, NULL);
	ft_lstclear(&b, NULL);
	return (0);
}
