/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:30:43 by rafernan          #+#    #+#             */
/*   Updated: 2021/11/08 15:26:30 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "./libps/libps.h"
#include "./main.h"

static void	ps_prints(t_list *a, t_list *b)
{
	t_list	*ptr_a;
	t_list	*ptr_b;

	ptr_a = a;
	ptr_b = b;
	ft_putstr(1, "A:\t");
	while (ptr_a)
	{
		ft_putnbr(1, (long)(ptr_a->content));
		ft_putchar(1, ' ');
		ptr_a = (ptr_a->next);
	}
	ft_putstr(1, "\nB:\t");
	while (ptr_b)
	{
		ft_putnbr(1, (long)(ptr_b->content));
		ft_putchar(1, ' ');
		ptr_b = (ptr_b->next);
	}
	ft_putchar(1, '\n');
}

static void	app(t_list **a)
{
	t_list	*b;
	char	*inpt;

	b = NULL;
	while (1)
	{
		inpt = get_next_line(0);
		if (ft_strncmp("sa", inpt, 2) == 0)
			ps_swap(a, '\0');
		else if (ft_strncmp("sb", inpt, 2) == 0)
			ps_swap(&b, '\0');
		else if (ft_strncmp("ss", inpt, 2) == 0)
		{
			ps_swap(a, '\0');
			ps_swap(&b, '\0');
		}
		else if (ft_strncmp("rra", inpt, 3) == 0)
			ps_rrot(a, '\0');
		else if (ft_strncmp("rrb", inpt, 3) == 0)
			ps_rrot(&b, '\0');
		else if (ft_strncmp("rrr", inpt, 3) == 0)
		{
			ps_rrot(a, '\0');
			ps_rrot(&b, '\0');
		}
		else if (ft_strncmp("pa", inpt, 2) == 0)
			ps_push(a, &b, '\0');
		else if (ft_strncmp("pb", inpt, 2) == 0)
			ps_push(&b, a, '\0');
		else if (ft_strncmp("ra", inpt, 2) == 0)
			ps_rot(a, '\0');
		else if (ft_strncmp("rb", inpt, 2) == 0)
			ps_rot(&b, '\0');
		else if (ft_strncmp("rr", inpt, 2) == 0)
		{
			ps_rot(a, '\0');
			ps_rot(&b, '\0');
		}
		else if (ft_strncmp("q", inpt, 1) == 0)
		{
			ft_lstclear(&b, NULL);
			free(inpt);
			return ;
		}
		if (inpt)
			free(inpt);
		inpt = NULL;
		ps_prints(*a, b);
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack;
	t_list	*helper;
	(void)(app);

	helper = NULL;
	if (argc <= 1)
		ft_putstr(2, "Usage: ./push_swap 0 1 2 3\n");
	stack = ps_lstatoi(argv + 1, argc - 1);
	if (!stack)
		return (-1);
	//app(&stack);
	ps_alg1(&stack, &helper);
	if (ps_issorted(stack) == 0)
		ft_putstr(1, "\033[32mOK\033[39m\n");
	else
		ft_putstr(1, "\033[31mKO\033[39m\n");
	ft_lstiter(stack, putlongv);
	ft_lstclear(&stack, NULL);
	return (0);
}
