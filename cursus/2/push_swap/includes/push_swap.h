/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:43:20 by ymanchon          #+#    #+#             */
/*   Updated: 2024/06/17 13:43:52 by bama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft.h"

typedef struct s_items
{
	int		data;
	int		cost;
	int		i;
}	t_items;

typedef struct s_stack
{
	t_items	*s;
	int		len;
}	t_stack;

void	calcul_cost(t_stack *a, t_stack *b);
t_items	find_mostpoor(t_stack *a);
char	is_a_sorted(t_stack *a);
char	is_b_sorted(t_stack *b);
void	poor_at_top(t_items *item, t_stack *a, int a_len);
void	place_item(t_items *item, t_stack *a, t_stack *b, int b_len);
void	show_stack(t_stack *a);
void	push_swap_two_a(t_stack *a);
void	push_swap_two_b(t_stack *b);
void	push_swap_three_a(t_stack *a);
void	push_swap_three_b(t_stack *b);
void	pa(t_stack *b, t_stack *a);
void	pb(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	swap(t_items *i1, t_items *i2);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

#endif