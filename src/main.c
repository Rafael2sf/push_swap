/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:30:43 by rafernan          #+#    #+#             */
/*   Updated: 2021/11/16 15:58:38 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "./libps/libps.h"

static void	push_swap(t_list **a, t_list **b, size_t len)
{
	if (!*a || len <= 1 || ps_issorted(*a) == 0)
		return ;
	if (len <= 5)
		return (ps_osort5(a, b, len, ps_lstavg(*a, len)));
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

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	if (argc <= 1)
	{
		ft_putstr(2, "Usage: ./push_swap 0 1 2 3\n");
		exit(1);
	}
	b = NULL;
	a = ps_lstatoi(argv + 1, argc - 1);
	if (!a)
	{
		ft_putstr(2, "Error\n");
		return (2);
	}
	push_swap(&a, &b, argc - 1);
	show(a, b);
	if (!b && ps_issorted(a) == 0)
		ft_putstr(1, "\033[32mOK\033[39m\n");
	else
		ft_putstr(1, "\033[31mKO\033[39m\n");
	ft_lstclear(&a, NULL);
	ft_lstclear(&b, NULL);
	return (0);
}
