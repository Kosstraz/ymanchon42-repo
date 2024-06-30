/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:13:46 by ymanchon          #+#    #+#             */
/*   Updated: 2024/06/18 12:41:49 by bama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show_stack(t_stack *s, const char *msg)
{
	while (s->len--)
		ft_printf("stack %s : %d\n", msg, s->s[s->len].data);
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

void	poor_at_top(t_items *item, t_stack *a, int a_len, char **ops)
{
	int	i;

	i = 0;
	if (item->i < a_len / 2)
		while (i++ < item->i + 1)
			rra(a, ops);
	else
		while (i++ < a_len - item->i)
			ra(a, ops);
}

void	place_item(t_items *item, t_stack *a, t_stack *b, char **ops)
{
	int	j;
	int	h;
	int	b_len;

	b_len = b->len;
	j = 0;
	while (j < b_len)
	{
		if (item->data < b->s[j].data)
		{
			h = 0;
			while (h++ < j)
				rrb(b, ops);
			pb(a, b, ops);
			h = 0;
			while (h++ < j)
				rb(b, ops);
			rb(b, ops);
			break ;
		}
		else if (j == b_len - 1)
			pb(a, b, ops);
		j++;
	}
}
