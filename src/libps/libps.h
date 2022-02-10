/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libps.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 20:21:13 by rafernan          #+#    #+#             */
/*   Updated: 2021/11/25 11:48:31 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPS_H
# define LIBPS_H

# include "../libft/libft.h"
# include <ctype.h>

typedef t_list	t_stack;

#define PS_GROUP 50

int		ps_atoi_l(const char *str, int *nbr);
t_stack	*ps_to_stack(char **argv, unsigned int size);

int		ps_lstfind(t_stack *stack, int nbr);
int		ps_issorted(t_stack *a);
int		ps_lstavg(t_stack *s, size_t len);
int		ps_lstmaxp(t_stack *a, int len);
int		ps_lstmin(t_list *a);
int		ps_getgroup(t_stack *a, int len);

int		ps_at(t_stack *s, int loc);
void	ps_do(t_stack **a, t_stack **b, void (*f)(t_stack**, t_stack**, int));
void	ps_to_top(t_stack **a, char sign, int val);

void	sa(t_stack **a, t_stack **b, int print);
void	sb(t_stack **a, t_stack **b, int print);
void	pa(t_stack **a, t_stack **b, int print);
void	pb(t_stack **a, t_stack **b, int print);
void	ra(t_stack **a, t_stack **b, int print);
void	rb(t_stack **a, t_stack **b, int print);
void	rra(t_stack **a, t_stack **b, int print);
void	rrb(t_stack **a, t_stack **b, int print);
void	ss(t_stack **a, t_stack **b, int print);
void	rr(t_stack **a, t_stack **b, int print);
void	rrr(t_stack **a, t_stack **b, int print);

void	ps_osort3(t_stack **s);
void	ps_osort5(t_stack **a, t_stack **b, int len);
void	ps_sort100(t_stack **a, t_stack **b, int len);

void	show(t_list *a, t_stack *b);

#endif