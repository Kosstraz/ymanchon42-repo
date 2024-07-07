/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:33:11 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/06 18:06:00 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_mid(const t_item item, const t_stack *b)
{
	int	i;

	i = cost_sub_of_min(item, b);
	if (i >= 0)
		return (i);
	i = cost_top_of_max(item, b);
	if (i >= 0)
		return (i);
	if (item.data > b->item[b->len - 1].data && item.data < b->item[0].data)
		return (b->len - 1);
	i = 0;
	while (i < b->len)
	{
		if (item.data > b->item[i].data && item.data < b->item[i + 1].data)
			return (i);
		i++;
	}
	return (0);
}

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
		j = find_mid(a->item[i], b);
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
	int		i;
	int		bool_;

	if (sub_of_min(a, b, inst, poor_i) || top_of_max(a, b, inst, poor_i))
		return ;
	else if (a->item[poor_i].data > b->item[b->len - 1].data
		&& a->item[poor_i].data < b->item[0].data)
		return (poor_at_top(a, inst, poor_i), pb(a, b, inst));
	i = 0;
	bool_ = 0;
	while (i < b->len && !bool_)
	{
		if (i < b->len - 1 && a->item[poor_i].data > b->item[i].data
			&& a->item[poor_i].data < b->item[i + 1].data)
		{
			set_offset(b, inst, i);
			poor_at_top(a, inst, poor_i);
			pb(a, b, inst);
			bool_ = 1;
		}
		i++;
	}
}
