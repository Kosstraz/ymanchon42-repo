/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 17:07:42 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/06 17:26:49 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cost_top_of_max(const t_item item, const t_stack *b)
{
	int		i;
	t_item	max;

	i = 0;
	while (i < b->len && item.data > b->item[i].data)
		i++;
	if (i == b->len)
	{
		i = -1;
		max = b->item[0];
		while (++i < b->len)
			if (max.data < b->item[i].data)
				max = b->item[i];
		if (max.i < b->len / 2)
			return (max.i);
		return (max.i);
	}
	return (-1);
}

int	cost_sub_of_min(const t_item item, const t_stack *b)
{
	int		i;
	t_item	min;

	i = 0;
	while (i < b->len && item.data < b->item[i].data)
		i++;
	if (i == b->len)
	{
		i = -1;
		min = b->item[0];
		while (++i < b->len)
			if (min.data > b->item[i].data)
				min = b->item[i];
		if (min.i < b->len / 2)
			return (min.i - 1);
		return (min.i - 1);
	}
	return (-1);
}
