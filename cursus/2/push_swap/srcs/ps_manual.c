/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_manual.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:15:27 by ymanchon          #+#    #+#             */
/*   Updated: 2024/06/17 16:00:59 by bama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_two_a(t_stack *a)
{
	if (a->s[a->len - 1].data > a->s[a->len - 2].data)
		sa(a);
}

void	push_swap_two_b(t_stack *b)
{
	if (b->s[b->len - 1].data < b->s[b->len - 2].data)
		sb(b);
}

void	push_swap_three_a(t_stack *a)
{
	if (a->s[0].data > a->s[1].data
		&& a->s[0].data > a->s[2].data)
		push_swap_two_a(a);
	else if (a->s[0].data < a->s[1].data
		&& a->s[0].data < a->s[2].data)
	{
		push_swap_two_a(a);
		rra(a);
	}
	else if (a->s[0].data > a->s[1].data
		&& a->s[0].data < a->s[2].data)
		ra(a);
	else if (a->s[0].data < a->s[1].data
		&& a->s[0].data > a->s[2].data)
	{
		if (a->s[1].data > a->s[2].data)
			sa(a);
		ra(a);
	}
	else if (a->s[2].data > a->s[1].data
		&& a->s[2].data > a->s[0].data)
	{
		push_swap_two_a(a);
		rra(a);
	}
}

void	push_swap_three_b(t_stack *b)
{
	if (b->s[2].data < b->s[1].data
		&& b->s[2].data < b->s[0].data)
	{
		rb(b);
		push_swap_two_b(b);
	}
	else if (b->s[2].data > b->s[1].data
		&& b->s[2].data > b->s[0].data)
	{
		if (b->s[1].data < b->s[0].data)
			rb(b);
		if (!is_b_sorted(b))
		{
			sb(b);
			rrb(b);
		}
	}
	else if (b->s[2].data < b->s[1].data
		&& b->s[2].data > b->s[0].data)
		sb(b);
	else if (b->s[2].data > b->s[1].data
		&& b->s[2].data < b->s[0].data)
		rrb(b);
	else if (b->s[0].data < b->s[1].data
		&& b->s[0].data < b->s[2].data)
		push_swap_two_b(b);
}
