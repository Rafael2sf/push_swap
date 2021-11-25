/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:30:43 by rafernan          #+#    #+#             */
/*   Updated: 2021/11/25 11:59:23 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libps/libps.h"

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
