/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:30:43 by rafernan          #+#    #+#             */
/*   Updated: 2021/11/07 22:52:55 by rafernan         ###   ########.fr       */
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
		if (ft_strncmp("w", inpt, 1) == 0)
			ps_prints(*a, b);
		else if (ft_strncmp("sa", inpt, 2) == 0)
			ps_swap(a, 'a');
		else if (ft_strncmp("sb", inpt, 2) == 0)
			ps_swap(&b, 'b');
		else if (ft_strncmp("ss", inpt, 2) == 0)
		{
			ps_swap(a, 'a');
			ps_swap(&b, 'b');
		}
		else if (ft_strncmp("rra", inpt, 3) == 0)
			ps_rrot(a, 'a');
		else if (ft_strncmp("rrb", inpt, 3) == 0)
			ps_rrot(&b, 'b');
		else if (ft_strncmp("rrr", inpt, 3) == 0)
		{
			ps_rrot(a, 'a');
			ps_rrot(&b, 'b');
		}
		else if (ft_strncmp("pa", inpt, 2) == 0)
			ps_push(a, &b, 'a');
		else if (ft_strncmp("pb", inpt, 2) == 0)
			ps_push(&b, a, 'b');
		else if (ft_strncmp("ra", inpt, 2) == 0)
			ps_rot(a, 'a');
		else if (ft_strncmp("rb", inpt, 2) == 0)
			ps_rot(&b, 'b');
		else if (ft_strncmp("rr", inpt, 2) == 0)
		{
			ps_rot(a, 'a');
			ps_rot(&b, 'b');
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
	}
}

int	main(int argc, char **argv)
{
	(void)(app);
	t_list	*stack;
	t_list	*helper;

	helper = NULL;
	if (argc <= 1)
		ft_putstr(2, "Usage: ./push_swap 0 1 2 3\n");
	stack = ps_lstatoi(argv + 1, argc - 1);
	if (!stack)
		return (-1);
	//app(&stack);
	ps_alg1(&stack, &helper);
	ft_lstiter(stack, ps_show);
	ft_lstclear(&stack, NULL);
	return (0);
}
