/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:30:43 by rafernan          #+#    #+#             */
/*   Updated: 2021/11/09 15:47:44 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "./libps/libps.h"
#include "./main.h"

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
	//app(&stack);
	ps_main(&a, &b, argc - 1);
	if (ps_issorted(a) == 0)
		ft_putstr(1, "\033[32mOK\033[39m\n");
	else
		ft_putstr(1, "\033[31mKO\033[39m\n");
	ft_lstiter(a, ps_putvl);
	ft_lstclear(&a, NULL);
	return (0);
}
