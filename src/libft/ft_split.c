/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:35:41 by rafernan          #+#    #+#             */
/*   Updated: 2021/10/21 10:42:18 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_split_size(char const *s, char c)
{
	char	*str;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	str = (char *)(s);
	while (*(str + i) && *(str + i) == c)
		i++;
	if (!*(str + i))
		return (0);
	j++;
	while (*(str + i))
	{
		if (*(str + i) == c && *(str + i + 1)
			&& *(str + i + 1) != c)
			j++;
		i++;
	}
	return (j);
}

static char	**ft_split_helper(char **ptr, char const *s, char c, size_t size)
{
	char	*str;
	size_t	i;
	size_t	j;

	j = 0;
	str = (char *)(s);
	while (*str && j < size)
	{
		while (*str && *str == c)
			str++;
		i = 0;
		while (*(str + i) && *(str + i) != c)
			i++;
		ptr[j] = (char *)malloc(sizeof(char) * (i + 1));
		if (!ptr[j])
			return (NULL);
		ft_strlcpy(ptr[j], str, i + 1);
		j++;
		str = (str + i);
	}
	ptr[j] = NULL;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**tmp;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_split_size(s, c);
	tmp = (char **)malloc(sizeof(char *) * (size + 1));
	if (!tmp)
		return (NULL);
	ft_split_helper(tmp, s, c, size);
	return (tmp);
}
