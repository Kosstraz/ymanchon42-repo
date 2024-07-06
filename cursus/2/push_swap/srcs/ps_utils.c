/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:42:38 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/06 15:10:38 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	top_of_max(t_stack *a, t_stack *b, char **inst, int poor_i)
{
	int		i;
	t_item	max;

	i = 0;
	while (i < b->len && a->item[poor_i].data > b->item[i].data)
		i++;
	if (i == b->len)
	{
		i = -1;
		max = b->item[0];
		while (++i < b->len)
			if (max.data < b->item[i].data)
				max = b->item[i];
		i = 0;
		if (max.i < b->len / 2)
			while (i++ < max.i + 1)
				rrb(b, inst);
		else
			while (i++ < b->len - 1 - max.i)
				rb(b, inst);
		poor_at_top(a, inst, poor_i);
		pb(a, b, inst);
		return (1);
	}
	return (0);
}

char	sub_of_min(t_stack *a, t_stack *b, char **inst, int poor_i)
{
	int		i;
	t_item	min;

	i = 0;
	while (i < b->len && a->item[poor_i].data < b->item[i].data)
		i++;
	if (i == b->len)
	{
		i = -1;
		min = b->item[0];
		while (++i < b->len)
			if (min.data > b->item[i].data)
				min = b->item[i];
		i = 0;
		if (min.i < b->len / 2)
			while (i++ < min.i)
				rrb(b, inst);
		else
			while (i++ <= b->len - 1 - min.i)
				rb(b, inst);
		poor_at_top(a, inst, poor_i);
		pb(a, b, inst);
		return (1);
	}
	return (0);
}

void	set_offset(t_stack *b, char **inst, int i)
{
	int	j;

	j = 0;
	if (i < b->len / 2)
		while (j++ < i + 1)
			rrb(b, inst);
	else
		while (j++ < b->len - 1 - i)
			rb(b, inst);
}

void	final_offset(t_stack *b, char **inst)
{
	int		i;
	t_item	min;

	i = 0;
	min = b->item[0];
	while (i < b->len)
	{
		if (min.data > b->item[i].data)
			min = b->item[i];
		i++;
	}
	i = 0;
	if (min.i < b->len - 1)
		while (i++ < min.i)
			rrb(b, inst);
	else
		while (i++ < b->len - 1 - min.i)
			rb(b, inst);
}
