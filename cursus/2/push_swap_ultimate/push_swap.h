/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:01:17 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/03 13:38:54 by ymanchon         ###   ########.fr       */
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