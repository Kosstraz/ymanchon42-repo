/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:13:46 by ymanchon          #+#    #+#             */
/*   Updated: 2024/06/17 15:58:10 by bama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show_stack(t_stack *s)
{
	while (s->len--)
		ft_printf("stack : %d\n", s->s[s->len]);
}

char	is_a_sorted(t_stack *a)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->len)
	{
		j = i;
		while (j < a->len)
			if (a->s[i].data < a->s[j++].data)
				return (0);
		i++;
	}
	return (1);
}

char	is_b_sorted(t_stack *b)
{
	int	i;
	int	j;

	i = 0;
	while (i < b->len)
	{
		j = i;
		while (j < b->len)
			if (b->s[i].data > b->s[j++].data)
				return (0);
		i++;
	}
	return (1);
}

void	poor_at_top(t_items *item, t_stack *a, int a_len)
{
	int	i;

	i = 0;
	if (item->i < a_len / 2)
		while (i++ < item->i + 1)
			rra(a);
	else
		while (i++ < a_len - item->i)
			ra(a);
}

void	place_item(t_items *item, t_stack *a, t_stack *b, int b_len)
{
	int	j;
	int	h;

	j = 0;
	while (j < b_len)
	{
		if (item->data < b->s[j].data)
		{
			h = 0;
			while (h++ < j)
				rrb(b);
			pb(a, b);
			h = 0;
			while (h++ < j)
				rb(b);
			rb(b);
			break ;
		}
		else if (j == b_len - 1)
			pb(a, b);
		j++;
	}
}
