/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:00:27 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/07 13:22:03 by ymanchon         ###   ########.fr       */
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
	if (a->item[a->len - 3].data < a->item[a->len - 2].data)
	{
		sort_two(a, inst, 1);
		rra(a, inst);
	}
	sort_two(a, inst, 1);
}

void	sort_three_b(t_stack *b, char **inst)
{
	sort_two(b, inst, -1);
	if (b->item[b->len - 3].data > b->item[b->len - 2].data)
	{
		sort_two(b, inst, -1);
		rrb(b, inst);
	}
	sort_two(b, inst, -1);
}

void	sort_four(t_stack *a, t_stack *b, char **inst)
{
	int		i;
	t_item	min;

	i = 0;
	min = a->item[0];
	while (i < a->len)
	{
		if (min.data > a->item[i].data)
			min = a->item[i];
		i++;
	}
	i = 0;
	if (min.i < a->len / 2)
		while (i++ < min.i + 1)
			rra(a, inst);
	else
		while (i++ < a->len - 1 - min.i)
			ra(a, inst);
	pb(a, b, inst);
	sort_three_a(a, inst);
	pa(b, a, inst);
}

void	sort_five(t_stack *a, t_stack *b, char **inst)
{
	int		i;
	t_item	min;

	i = 0;
	min = a->item[0];
	while (i < a->len)
	{
		if (min.data > a->item[i].data)
			min = a->item[i];
		i++;
	}
	i = 0;
	if (min.i < a->len / 2)
		while (i++ < min.i + 1)
			rra(a, inst);
	else
		while (i++ < a->len - 1 - min.i)
			ra(a, inst);
	pb(a, b, inst);
	sort_four(a, b, inst);
	pa(b, a, inst);
}
