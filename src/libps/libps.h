/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libps.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 20:21:13 by rafernan          #+#    #+#             */
/*   Updated: 2021/11/18 15:26:09 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPS_H
# define LIBPS_H

# include "../libft/libft.h"

#define PS_BLOCK 20

/* Exits progam, freeing memory in case of error */
void	ps_exit(t_list	**stack, int ret);
/* Writes void as long number to stdout */
void	ps_putvl(void *x);

/* Convert a list of arguments to linked list of ints */
t_list	*ps_lstatoi(char **list, int size);
/* Converts str to nbr, if number overflows or underflows int returns 0 */
int		ps_atoi(const char *str, int *nbr);
/* Search for nbr in linked list */
int		ps_lstfind(t_list *s, int nbr);
/* Find the bigger nbr in a list till depth bytes */
int		ps_lstf_bigger(t_list *s, int nbr, size_t depth);
/* Calculates the avg of a linked list till len bytes */
int		ps_lstavg(t_list *a, size_t len);
/* Find the smallest value in a */
int		ps_lstmin(t_list *a);

/* Swap 2 at the top */
void	ps_swap(t_list **s, char ab);
/* Push top to other stack */
void	ps_push(t_list **a, t_list **b, char ab);
/* Rotates the stack, first becomes last */
void	ps_rot(t_list **s, char ab);
/* Rotates the stack, last becomes first */
void	ps_rrot(t_list **s, char ab);
/* Swap 2 stacks in one move */
void	ps_ss(t_list **a, t_list **b);
/* Rotate 2 stacks in on move */
void	ps_rr(t_list **a, t_list **b);
/* Reverse rotate 2 stacks in one move */
void	ps_rrr(t_list **a, t_list **b);

/* Temporary app function to test sorting moves */
void	app(t_list **a, t_list **b);
/* Temporary function to print stacks onto the screen */ 
void	ps_prints(t_list *a, t_list *b);

/* Check if stack is organized from smallest to bigger */
int		ps_issorted(t_list *a);
/* Optimized sort for list of size 3 */
void	ps_osort3(t_list **a, t_list **b);
/* Optimized sort for list of size 5 */
void	ps_osort5(t_list **a, t_list **b, size_t a_siz, int avg);
/* Sorts the list */
void	ps_sort(t_list **a, t_list **b);

void	ps_get_next(t_list **a, int val);
/* Calculates the block size based on PS_BLOCK */
int		ps_calcd(int len);
/*	Returns the correct value */
int		ps_magic(int avg, int min, int div);

#endif