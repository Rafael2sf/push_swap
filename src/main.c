/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 21:57:47 by rafernan          #+#    #+#             */
/*   Updated: 2022/01/20 21:57:47 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libps/libps.h"

void	pvai(void *n)
{
	ft_putnbr(STDOUT_FILENO, (int)(long)(n));
	ft_putchar(STDOUT_FILENO, ' ');
}

void	show(t_list *a, t_stack *b)
{
	t_stack	*tmp;

	tmp = a;
	if (a)
	{
		tmp = a;
		ft_lstiter(tmp, pvai);
		ft_putchar(STDOUT_FILENO, '\n');
	}
	if (b)
	{
		tmp = b;
		ft_lstiter(tmp, pvai);
		ft_putchar(STDOUT_FILENO, '\n');
	}
}

static void	push_swap(t_stack **a, t_stack **b, int len)
{
	if (len == 2)
	{
		if (ps_at(*a, 0) > ps_at(*a, 1))
			ps_do(a, NULL, sa);
	}
	else if (len == 3)
		ps_osort3(a);
	else if (len <= 5)
		ps_osort5(a, b, len);
	else
		ps_sort100(a, b, len);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc <= 1)
		return (0);
	a = ps_to_stack(argv + 1, argc - 1);
	if (!a)
	{
		ft_putstr(STDERR_FILENO, "Error\n");
		return (1);
	}
	b = NULL;
	if (ps_issorted(a) != 0)
		push_swap(&a, &b, argc - 1);
	ft_lstclear(&a, NULL);
	ft_lstclear(&b, NULL);
	return (0);
}
