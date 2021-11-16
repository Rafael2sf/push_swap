/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libps.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 20:21:13 by rafernan          #+#    #+#             */
/*   Updated: 2021/11/16 14:57:00 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPS_H
# define LIBPS_H

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
void	ps_ss(t_list **a, t_list **b);
void	ps_rr(t_list **a, t_list **b);
void	ps_rrr(t_list **a, t_list **b);

void	app(t_list **a, t_list **b);
void	ps_prints(t_list *a, t_list *b);

int		ps_issorted(t_list *a);
void	ps_osort3(t_list **a, t_list **b);
void	ps_osort5(t_list **a, t_list **b, size_t a_siz, int avg);
void	ps_sort100(t_list **a, t_list **b, size_t len);

#endif