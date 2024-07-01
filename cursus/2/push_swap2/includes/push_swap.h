/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:43:20 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/01 15:57:39 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft.h"

typedef struct s_op_handle
{
	char	*op1;
	char	*op2;
	char	*new;
}	t_op_handle;

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

void	optimize(char **ops);
void	calcul_cost(t_stack *a, t_stack *b);
t_items	find_mostpoor(t_stack *a);
char	is_a_sorted(t_stack *a);
char	is_b_sorted(t_stack *b);
void	poor_at_top(t_items *item, t_stack *a, int a_len, char **ops);
void	place_item(t_items *item, t_stack *a, t_stack *b, char **ops);
void	show_stack(t_stack *a, const char *msg);
void	push_swap_two_a(t_stack *a, char **ops);
void	push_swap_two_b(t_stack *b, char **ops);
void	push_swap_three_a(t_stack *a, char **ops);
void	push_swap_three_b(t_stack *b, char **ops);
void	pa(t_stack *b, t_stack *a, char **ops);
void	pb(t_stack *a, t_stack *b, char **ops);
void	rra(t_stack *a, char **ops);
void	rrb(t_stack *b, char **ops);
void	rrr(t_stack *a, t_stack *b, char **ops);
void	ra(t_stack *a, char **ops);
void	rb(t_stack *b, char **ops);
void	rr(t_stack *a, t_stack *b, char **ops);
void	swap(t_items *i1, t_items *i2);
void	sa(t_stack *a, char **ops);
void	sb(t_stack *b, char **ops);
void	ss(t_stack *a, t_stack *b, char **ops);

#endif