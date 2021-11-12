/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 00:02:07 by rafernan          #+#    #+#             */
/*   Updated: 2021/11/11 15:33:30 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libps.h"

void	ps_putvl(void *x)
{
	ft_putnbr(1, (long)(x));
	ft_putchar(1, ' ');
}

void	ps_exit(t_list **stack, int ret)
{
	ft_lstclear(stack, NULL);
	ft_putendl(2, "Error");
	exit(ret);
}
