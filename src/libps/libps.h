/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libps.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 20:21:13 by rafernan          #+#    #+#             */
/*   Updated: 2021/11/08 12:51:18 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPS_H
# define LIBPS_H

# include "../main.h"
# include "../libft/libft.h"

void	ps_exit(t_list	**stack, int ret);
void	putlongv(void *x);

t_list	*ps_lstatoi(char **list, int size);

void	ps_swap(t_list **s, char ab);
void	ps_push(t_list **a, t_list **b, char ab);
void	ps_rot(t_list **s, char ab);
void	ps_rrot(t_list **s, char ab);
int		ps_issorted(t_list	*a);

void	ps_alg1(t_list **a, t_list **b);
void	ps_alg2(t_list **a, t_list **b);

#endif