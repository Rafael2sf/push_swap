/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:30:43 by rafernan          #+#    #+#             */
/*   Updated: 2021/11/12 15:21:12 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "./libps/libps.h"
#include "./main.h"

/* Divide stack A, into 2 parts, half goes to B, divided by average */
void	sort(t_list **a, t_list **b, int len)
{
	int 	mid;
	t_list	*tmp;
	int		last;
	
	if (len <= 2)
		return ;
	mid = ps_lstavg(*a);
	while ((long)((*a)->content) < mid)
		ps_push(b, a, 'b');
	last = ((long)((*a)->content));
	ps_rot(a, 'a');
	tmp = (*a);
	while (tmp && (long)(tmp->content) != last)
	{
		if ((long)((*a)->content) < mid)
			ps_push(b, a, 'b');
		else
			ps_rot(a, 'a');
		tmp = (*a);
	}
}

void	sortr(t_list **a, t_list **b, int len)
{
	int	avg;
	int bvg;

	if (len <= 2)
		return ;
	avg = ps_lstavg(*a);
	bvg = ps_lstavg(*b);
	if ((long)((*a)->content) < avg)
	{
		ps_push(b, a, 'b');
		if ((long)((*b)->content) < bvg)
			ps_rot(b, 'b');
		sortr(a, b, len - 1);
	}
	else if ((long)(ft_lstlast(*a)->content) < avg)
	{
		ps_rrot(a, 'a');
		ps_push(b, a, 'b');
		sortr(a, b, len - 1);
	}
	else
	{
		ps_rot(a, 'a');
		sortr(a, b, len);	
	}
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	
	b = NULL;
	if (argc <= 1)
	{
		ft_putstr(2, "Usage: ./push_swap 0 1 2 3\n");
		exit(1);
	}
	a = ps_lstatoi(argv + 1, argc - 1);
	if (!a)
	{
		ft_putendl(1, "Error");
		return (2);
	}
	app(&a);
	//sortr(&a, &b, argc - 1);
	/*
	if (ps_issorted(a) == 0)
		ft_putstr(1, "\033[32mOK\033[39m\n");
	else
		ft_putstr(1, "\033[31mKO\033[39m\n");
	*/
	ft_lstiter(a, ps_putvl);
	ft_putstr(1, "\n ------ \n");
	ft_lstiter(b, ps_putvl);
	ft_lstclear(&a, NULL);
	return (0);
}
