/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_cost.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:09:56 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/01 17:02:19 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calcul_cost(t_stack *a, t_stack *b)
{
	int	b_cost;
	int	i;
	int	j;

	i = 0;
	while (i < a->len)
	{
		if (i < a->len / 2)
			a->s[i].cost = (i + 2);
		else
			a->s[i].cost = (a->len - i);
		j = 0;
		b_cost = 0;
		/*while (b_cost == 0 && j < b->len)
		{
			if (a->s[i].data < b->s[j].data)
				b_cost = (0);
			j++;
		}*/
		while (b_cost == 0 && j < b->len
			&& a->s[i].data > b->s[b->len - 1].data)
		{
			if (a->s[i].data < b->s[j].data)
				b_cost = ((j * 2) + 1);
			j++;
		}/**/
		a->s[i].cost += b_cost;
		i++;
	}
}

t_items	find_mostpoor(t_stack *a)
{
	t_items	poor;
	int		i;

	i = 0;
	poor = a->s[i++];
	while (i < a->len)
	{
		if (a->s[i].cost < poor.cost)
			poor = a->s[i];
		i++;
	}
	return (poor);
}
