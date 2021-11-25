/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_opers2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:35:58 by rafernan          #+#    #+#             */
/*   Updated: 2021/11/25 11:58:29 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	ps_ss(t_list **a, t_list **b)
{
	ps_swap(a, '\0');
	ps_swap(b, '\0');
	ft_putstr(1, "ss\n");
}

void	ps_rr(t_list **a, t_list **b)
{
	ps_rot(a, '\0');
	ps_rot(b, '\0');
	ft_putstr(1, "rr\n");
}

void	ps_rrr(t_list **a, t_list **b)
{
	ps_rrot(a, '\0');
	ps_rrot(b, '\0');
	ft_putstr(1, "rrr\n");
}
