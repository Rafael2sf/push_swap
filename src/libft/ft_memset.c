/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:55:14 by rafernan          #+#    #+#             */
/*   Updated: 2021/11/24 18:26:33 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	if (len <= 0)
		return (b);
	i = 0;
	if (b != NULL)
	{
		ptr = (unsigned char *)(b);
		while (i < len)
		{
			ptr[i] = (unsigned char)(c);
			i++;
		}
	}
	return (b);
}
