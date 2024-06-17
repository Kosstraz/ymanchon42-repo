/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 12:35:55 by ymanchon          #+#    #+#             */
/*   Updated: 2024/06/17 16:01:58 by bama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_swap_manual(t_stack *a, t_stack *b, int count)
{
	if (count == 2)
		push_swap_two_a(a);
	else if (count == 3)
		push_swap_three_a(a);
}

void	push_swap(t_stack *a, t_stack *b)
{
	int		i;
	t_items	poor;

	pb(a, b);
	pb(a, b);
	pb(a, b);
	push_swap_three_b(b);
	while (a->len)
	{
		calcul_cost(a, b);
		poor = find_mostpoor(a);
		poor_at_top(&poor, a, a->len);
		place_item(&poor, a, b, b->len);
	}
	i = b->len;
	while (a->len < i)
		pa(b, a);
}

int	main(int ac, char **av)
{
	int		i;
	int		j;
	t_stack	a;
	t_stack	b;

	if (ac > 2)
	{
		i = 0;
		while (i < ac - 1)
			(i)++;
		a.s = (t_items *)malloc(sizeof(t_items) * i);
		if (!a.s)
			return (0);
		b.s = (t_items *)malloc(sizeof(t_items) * i);
		if (!b.s)
			return (free(a.s), 0);
		a.len = i--;
		b.len = 0;
		j = 0;
		while (i >= 0)
		{
			a.s[i].data = ft_atoi(av[j++ + 1]);
			a.s[i].cost = -1;
			a.s[i].i = i--;
		}
		if (ac - 1 <= 3)
			push_swap_manual(&a, &b, ac - 1);
		else
			push_swap(&a, &b);
	}
	return (0);
}
