/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:01:17 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/06 17:08:06 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define N 500

# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

typedef struct s_op_handle
{
	char	*op1;
	char	*op2;
	char	*new;
}	t_op_handle;

typedef struct s_item
{
	int	data;
	int	cost;
	int	i;
}	t_item;

typedef struct s_stack
{
	t_item	item[N];
	int		len;
}	t_stack;

/*
	STACK HANDLE
*/

void	init_stack(t_stack *stack);
void	fill_stack(t_stack *a, int count, char **val);
void	show_stack(t_stack stack, const char *name);

/*
	SORT
*/

void	sort_two(t_stack *s, char **inst, int order);
void	sort_three_a(t_stack *a, char **inst);
void	sort_three_b(t_stack *b, char **inst);
void	sort_four_a(t_stack *a, char **inst);

/*
	BIG SORT
*/

void	calcul_cost(t_stack *a, const t_stack *b);
int		find_poor(const t_stack *a);
void	poor_at_top(t_stack *a, char **inst, int poor_i);
void	place_poor(t_stack *a, t_stack *b, char **inst, int poor_i);

/*
	UTILS
*/

char	top_of_max(t_stack *a, t_stack *b, char **inst, int poor_i);
char	sub_of_min(t_stack *a, t_stack *b, char **inst, int poor_i);
void	set_offset(t_stack *b, char **inst, int i);
void	final_offset(t_stack *b, char **inst);
int		cost_top_of_max(const t_item item, const t_stack *b);
int		cost_sub_of_min(const t_item item, const t_stack *b);

/*
	OPTI
*/

void	optimize(char **inst);

/*
	PARSING
*/

char	check_av(int ac, char **av);

/*
	INSTRUCTIONS
*/

void	swap(t_item *s1, t_item *s2);
void	pa(t_stack *b, t_stack *a, char **ops);
void	pb(t_stack *a, t_stack *b, char **ops);
void	sa(t_stack *a, char **ops);
void	sb(t_stack *b, char **ops);
void	ss(t_stack *a, t_stack *b, char **ops);
void	ra(t_stack *a, char **ops);
void	rra(t_stack *a, char **ops);
void	rb(t_stack *b, char **ops);
void	rrb(t_stack *b, char **ops);
void	rr(t_stack *a, t_stack *b, char **ops);
void	rrr(t_stack *a, t_stack *b, char **ops);

#endif