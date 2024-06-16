/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:43:20 by ymanchon          #+#    #+#             */
/*   Updated: 2024/06/16 16:52:18 by ymanchon         ###   ########.fr       */
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
	int		target;
}	t_items;

typedef struct s_stack
{
	t_items	*s;
	int		len;
}	t_stack;

char	is_a_sorted(t_stack *a);
char	is_b_sorted(t_stack *b);
void	show_stack(t_stack *a);
void	push_swap_two(t_stack *a);
void	push_swap_three(t_stack *a, t_stack *b);
void	push_swap_four(t_stack *a, t_stack *b);
void	push_swap_five(t_stack *a, t_stack *b);
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