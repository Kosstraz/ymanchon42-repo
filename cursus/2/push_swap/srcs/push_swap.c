/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:07:11 by ymanchon          #+#    #+#             */
/*   Updated: 2024/06/14 14:25:33 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_manual(t_stack *a, t_stack *b, int count)
{
	if (count == 2)
		push_swap_two(a, b);
	else if (count == 3)
		push_swap_three(a, b);
	else
	{
		if (count == 4)
			push_swap_four(a, b);
		else if (count == 5)
			push_swap_five(a, b);
	}
	free(a->s);
	free(b->s);
}

// De MIN a MAX (dans 'b')
// Puis tout push dans 'a'
// Au lieu de faire que des ra, calculer ou est le prochain
//element (le plus proche : vers le haut ou le bas ?), puis faire ra ou rb
void	ps_push_tob(t_stack *a, t_stack *b)
{
	int	dicho;
	int	i;

	i = 0;
	while (a->len)
	{
		while (i != a->s[a->len - 1].i)
		{
			dicho = ps_find_dicho(a, i);
			if (dicho >= 0 && !ps_estimate_dicho(a, i))
				ra(a);
			else if (dicho >= 0)
				sa(a);
			else
				rra(a);
		}
		pb(a, b);
		i++;
	}
}

void	ps_push_toa(t_stack *a, t_stack *b)
{
	while (b->len)
		pa(b, a);
}

void	push_swap(t_stack *a, t_stack *b)
{
	ps_add_to_btree(a);
	ps_push_tob(a, b);
	ps_push_toa(a, b);
	//show_stack(a);
	free(a->s);
	free(b->s);
}

int	main(int ac, char **av)
{
	int		i;
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
		a.len = i;
		b.len = 0;
		while (i-- > 0)
		{
			a.s[i].data = ft_atoi(av[i + 1]);
			a.s[i].i = 0;
		}
		if (ac <= 6)
			push_swap_manual(&a, &b, ac - 1);
		else
			push_swap(&a, &b);
	}
	return (0);
}
