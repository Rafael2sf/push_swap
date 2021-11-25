/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:08:38 by rafernan          #+#    #+#             */
/*   Updated: 2021/11/25 11:58:38 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

static int	ps_limits(int *nbr, const char *str, int flag)
{
	if (*nbr > (INT_MAX / 10))
		return (0);
	if (*nbr == (INT_MAX / 10) && flag == 1 && *str > '7')
		return (0);
	if (*nbr == (INT_MAX / 10) && flag == -1 && *str > '8')
		return (0);
	return (1);
}

int	ps_atoi(const char *str, int *nbr)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	(*nbr) = 0;
	if (*str == '-' && str++)
		flag = -1;
	while (*str == '0')
		str++;
	while (ft_isdigit(str[i]))
	{
		if (i > 9)
			break ;
		if (i == 9)
		{
			if (!ps_limits(nbr, str + i, flag))
				return (0);
		}
		(*nbr) = ((*nbr) * 10) + (str[i++] - '0');
	}
	if (str[i] != '\0')
		return (0);
	(*nbr) *= flag;
	return (1);
}
