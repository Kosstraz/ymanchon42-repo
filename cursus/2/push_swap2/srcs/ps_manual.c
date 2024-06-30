/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_manual.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:15:27 by ymanchon          #+#    #+#             */
/*   Updated: 2024/06/18 12:31:05 by bama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_two_a(t_stack *a, char **ops)
{
	if (a->s[a->len - 1].data > a->s[a->len - 2].data)
		sa(a, ops);
}

void	push_swap_two_b(t_stack *b, char **ops)
{
	if (b->s[b->len - 1].data < b->s[b->len - 2].data)
		sb(b, ops);
}

void	push_swap_three_a(t_stack *a, char **ops)
{
	if (a->s[0].data > a->s[1].data
		&& a->s[0].data > a->s[2].data)
		push_swap_two_a(a, ops);
	else if (a->s[0].data < a->s[1].data
		&& a->s[0].data < a->s[2].data)
	{
		push_swap_two_a(a, ops);
		rra(a, ops);
	}
	else if (a->s[0].data > a->s[1].data
		&& a->s[0].data < a->s[2].data)
		ra(a, ops);
	else if (a->s[0].data < a->s[1].data
		&& a->s[0].data > a->s[2].data)
	{
		if (a->s[1].data > a->s[2].data)
			sa(a, ops);
		ra(a, ops);
	}
	else if (a->s[2].data > a->s[1].data
		&& a->s[2].data > a->s[0].data)
	{
		push_swap_two_a(a, ops);
		rra(a, ops);
	}
}

void	push_swap_three_b(t_stack *b, char **ops)
{
	if (b->s[2].data < b->s[1].data
		&& b->s[2].data < b->s[0].data)
	{
		rb(b, ops);
		push_swap_two_b(b, ops);
	}
	else if (b->s[2].data > b->s[1].data
		&& b->s[2].data > b->s[0].data)
	{
		if (b->s[1].data < b->s[0].data)
			rb(b, ops);
		if (!is_b_sorted(b))
		{
			sb(b, ops);
			rrb(b, ops);
		}
	}
	else if (b->s[2].data < b->s[1].data
		&& b->s[2].data > b->s[0].data)
		sb(b, ops);
	else if (b->s[2].data > b->s[1].data
		&& b->s[2].data < b->s[0].data)
		rrb(b, ops);
	else if (b->s[0].data < b->s[1].data
		&& b->s[0].data < b->s[2].data)
		push_swap_two_b(b, ops);
}
