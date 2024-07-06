/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:08:29 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/06 17:43:02 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_swap(t_stack *a, t_stack *b, char **inst)
{
	int	poor_i;

	pb(a, b, inst);
	pb(a, b, inst);
	sort_two(b, inst, -1);
	while (a->len)
	{
		calcul_cost(a, b);
		poor_i = find_poor(a);
		place_poor(a, b, inst, poor_i);
	}
	final_offset(b, inst);
	while (b->len)
		pa(b, a, inst);
}

void	sort(t_stack *a, t_stack *b, char **inst, int count)
{
	(void)b;
	if (count == 2)
		sort_two(a, inst, 1);
	else if (count == 3)
		sort_three_a(a, inst);
	else if (count == 4)
		sort_four_a(a, inst);
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	char	*inst;

	if (ac >= 3 && ac <= 501)
	{
		//if (!check_av(ac - 1, &av[1]))
		//{	
		//	ft_printf("Error\n");
		//	return (0);
		//}
		init_stack(&a);
		init_stack(&b);
		fill_stack(&a, ac - 1, &av[1]);
		if (ac <= 5)
			sort(&a, &b, &inst, ac - 1);
		else
			push_swap(&a, &b, &inst);
		optimize(&inst);
		if (inst)
			ft_printf("%s", inst);
	}
	return (0);
}
