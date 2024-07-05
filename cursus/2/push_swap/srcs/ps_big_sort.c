/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:33:11 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/05 19:01:54 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calcul_cost(t_stack *a, const t_stack *b)
{
	int	i;
	int	j;
	int	cost;

	i = 0;
	while (i < a->len)
	{
		if (i < a->len / 2)
			cost = (i + 2);
		else
			cost = (a->len - i);
		j = b->len - 1;
		while (j >= 0 && a->item[i].data < b->item[j].data)
			j--;
		if (j < b->len / 2)
			cost += (j + 1);
		else
			cost += (b->len - 1 - j);
		a->item[i++].cost = cost;
	}
}

int	find_poor(const t_stack *a)
{
	int	i;
	int	cost;
	int	poor_i;

	i = 0;
	cost = a->item[a->len - 1].cost;
	poor_i = a->len - 1;
	while (i < a->len - 1)
	{
		if (a->item[i].cost < cost)
		{
			cost = a->item[i].cost;
			poor_i = i;
		}
		i++;
	}
	return (poor_i);
}

void	poor_at_top(t_stack *a, char **inst, int poor_i)
{
	int	i;

	i = 0;
	if (poor_i < a->len / 2)
		while (i++ < poor_i + 1)
			rra(a, inst);
	else
		while (i++ < a->len - 1 - poor_i)
			ra(a, inst);
}

void	place_poor(t_stack *a, t_stack *b, char **inst, int poor_i)
{
	int	bool_;
	int	i;
	int	j;

	i = 0;
	if (a->item[poor_i].data > b->item[b->len - 1].data)
		return (poor_at_top(a, inst, poor_i), pb(a, b, inst));
	bool_ = 0;
	while (i < b->len && !bool_)
	{
		if (a->item[poor_i].data < b->item[i].data)
		{
			j = 0;
			if (i < b->len / 2)
			{
				while (j++ < i)
					rrb(b, inst);
				poor_at_top(a, inst, poor_i);
				pb(a, b, inst);
				j = 0;
				//while (j++ < i + 1)
					//rb(b, inst);
			}
			else
			{
				while (j++ <= b->len - 1 - i)
					rb(b, inst);
				poor_at_top(a, inst, poor_i);
				pb(a, b, inst);
				j = 0;
				//while (j++ < b->len - 1 - i)
					//rrb(b, inst);
			}
			bool_ = 1;
		}
		i++;
	}
}
