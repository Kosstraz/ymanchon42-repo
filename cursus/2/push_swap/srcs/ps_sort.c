/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:00:27 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/06 14:21:59 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *s, char **inst, int order)
{
	if (order > 0)
	{
		if (s->item[s->len - 2].data < s->item[s->len - 1].data)
			sa(s, inst);
	}
	else if (order < 0)
		if (s->item[s->len - 2].data > s->item[s->len - 1].data)
			sb(s, inst);
}

void	sort_three_a(t_stack *a, char **inst)
{
	sort_two(a, inst, 1);
	ra(a, inst);
	sort_two(a, inst, 1);
	rra(a, inst);
	sort_two(a, inst, 1);
}

void	sort_three_b(t_stack *b, char **inst)
{
	sort_two(b, inst, -1);
	rb(b, inst);
	sort_two(b, inst, -1);
	rrb(b, inst);
	sort_two(b, inst, -1);
}

void	sort_four_a(t_stack *s, char **inst)
{
	sort_three_a(s, inst);
	ra(s, inst);
	sort_three_a(s, inst);
	rra(s, inst);
	sort_three_a(s, inst);
}
