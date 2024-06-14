/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:43:20 by ymanchon          #+#    #+#             */
/*   Updated: 2024/06/14 14:23:30 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft.h"

typedef struct s_items
{
	int		data;
	int		i;
}	t_items;

typedef struct s_stack
{
	t_items	*s;
	int		len;
}	t_stack;

typedef struct s_pbtree
{
	t_items			*item;
	struct s_pbtree	*left;
	struct s_pbtree	*right;
}	t_pbtree;

t_pbtree	*ps_btree_create_node(t_items *item);
void		ps_btree_infix(t_pbtree **root, int *i);
void		ps_btree_free_suffix(t_btree *root, void (*applyf)(void *));
void		ps_btree_insert_data(t_pbtree **root, t_items *item,
				int (*cmpf)(int, int));
void		ps_add_to_btree(t_stack *a);
int			ps_find_dicho(t_stack *a, int idx);
int			ps_estimate_dicho(t_stack *a, int idx);
void		show_stack(t_stack *a);
void		push_swap_two(t_stack *a, t_stack *b);
void		push_swap_three(t_stack *a, t_stack *b);
void		push_swap_four(t_stack *a, t_stack *b);
void		push_swap_five(t_stack *a, t_stack *b);
void		pa(t_stack *b, t_stack *a);
void		pb(t_stack *a, t_stack *b);
void		rra(t_stack *a);
void		rrb(t_stack *b);
void		rrr(t_stack *a, t_stack *b);
void		ra(t_stack *a);
void		rb(t_stack *b);
void		rr(t_stack *a, t_stack *b);
void		swap(t_items *i1, t_items *i2);
void		sa(t_stack *a);
void		sb(t_stack *b);
void		ss(t_stack *a, t_stack *b);

#endif