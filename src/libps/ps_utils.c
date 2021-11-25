/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 00:02:07 by rafernan          #+#    #+#             */
/*   Updated: 2021/11/25 11:51:05 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libps.h"

void	ps_exit(t_list **stack, int ret)
{
	ft_lstclear(stack, NULL);
	ft_putstr(2, "Error\n");
	exit(ret);
}
