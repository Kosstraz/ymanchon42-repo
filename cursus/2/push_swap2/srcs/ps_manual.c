/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_manual.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:15:27 by ymanchon          #+#    #+#             */
/*   Updated: 2024/06/16 16:11:19 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_two(t_stack *a)
{
	if (a->s[a->len - 1].data < a->s[a->len - 2].data)
		sa(a);
}

void	push_swap_three(t_stack *a, t_stack *b)
{
	if (a->s[0].data > a->s[1].data
		&& a->s[0].data < a->s[2].data)
		ra(a);
	else if (a->s[2].data > a->s[1].data
		&& a->s[2].data > a->s[0].data)
		push_swap_two(a);
	else
	{
		if (a->s[0].data > a->s[1].data
			&& a->s[0].data > a->s[2].data)
		{
			ra(a);
			push_swap_two(a);
		}
		else if (a->s[1].data > a->s[2].data
			&& a->s[1].data > a->s[0].data)
		{
			rra(a);
			push_swap_two(a);
		}
	}
}
