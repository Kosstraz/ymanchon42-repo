/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 12:35:55 by ymanchon          #+#    #+#             */
/*   Updated: 2024/06/16 16:52:30 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_swap(t_stack *a, t_stack *b)
{
	
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
			a.s[i].cost = -1;
			a.s[i].target = 0;
		}
		if (ac - 1 <= 3)
			push_swap_manual(&a, &b, ac - 1);
		else
			push_swap(&a, &b);
	}
	return (0);
}
