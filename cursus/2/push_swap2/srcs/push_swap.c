/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 12:35:55 by ymanchon          #+#    #+#             */
/*   Updated: 2024/06/30 14:06:06 by bama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_swap_manual(t_stack *a, t_stack *b, int count)
{
	char	*ops;

	ops = malloc(sizeof(char));
	ops[0] = '\0';
	if (count == 2)
		push_swap_two_a(a, &ops);
	else if (count == 3)
		push_swap_three_a(a, &ops);
	ft_printf("%s", ops);
	freemen(3, ops, a->s, b->s);
}

void	push_swap(t_stack *a, t_stack *b)
{
	int		i;
	char	*ops;
	int		ops_size;
	t_items	poor;

	ops = malloc(sizeof(char));
	ops[0] = '\0';
	pb(a, b, &ops);
	pb(a, b, &ops);
	pb(a, b, &ops);
	push_swap_three_b(b, &ops);
	while (a->len)
	{
		calcul_cost(a, b);
		poor = find_mostpoor(a);
		poor_at_top(&poor, a, a->len, &ops);
		place_item(&poor, a, b, &ops);
	}
	i = b->len;
	while (a->len < i)
		pa(b, a, &ops);
	//optimize(&ops, ops_size);
	write(1, ops, ft_strlen(ops));
	freemen(3, ops, a->s, b->s);
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
			a.s[i].i = i + 1;
			i--;
		}
		if (ac - 1 <= 3)
			push_swap_manual(&a, &b, ac - 1);
		else
			push_swap(&a, &b);
	}
	return (0);
}
