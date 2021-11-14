/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libps.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 20:21:13 by rafernan          #+#    #+#             */
/*   Updated: 2021/11/13 18:15:28 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPS_H
# define LIBPS_H

# include "../main.h"
# include "../libft/libft.h"

void	ps_exit(t_list	**stack, int ret);
void	ps_putvl(void *x);

t_list	*ps_lstatoi(char **list, int size);
int		ps_lstfind(t_list *s, int nbr);
int		ps_lstf_bigger(t_list *s, int nbr, size_t depth);
int		ps_lstavg(t_list *a, size_t len);

int		ps_atoi(const char *str, int *nbr);

void	ps_swap(t_list **s, char ab);
void	ps_push(t_list **a, t_list **b, char ab);
void	ps_rot(t_list **s, char ab);
void	ps_rrot(t_list **s, char ab);

int		ps_main(t_list **a, t_list **b, int len);
int		ps_issorted(t_list	*a);

void	ps_sort(t_list **a, t_list **b, int alen, int blen);

void	app(t_list **a, t_list **b);

#endif