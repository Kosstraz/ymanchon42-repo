/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:08:29 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/05 19:05:07 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_swap(t_stack *a, t_stack *b, char **inst)
{
	int	poor_i;

	pb(a, b, inst);
	pb(a, b, inst);
	pb(a, b, inst);
	sort_three_b(b, inst);
	/*printf("\t\tPB\n\n");
	show_stack(*a, "A(3)");
	show_stack(*b, "B(3)");*/
	while (a->len)
	{
		calcul_cost(a, b);
		poor_i = find_poor(a);
		//poor_at_top(a, inst, poor_i);
		place_poor(a, b, inst, poor_i);
		/*printf("\t\t%d\n\n", a->len);
		show_stack(*a, "A(x)");
		show_stack(*b, "B(x)");*/
	}
	/*		EZ		
	int 	i = 0;
	t_item	min;
	min = b->item[0];

	show_stack(*b, "B (FINAL)");
	while (i < b->len)
	{
		if (b->item[i].data < min.data)
			min = b->item[i];
		i++;
	}
	i = min.i;
	while (i-- >= 0)
		rb(b, inst);*/
	/*		FIN EZ	*/
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
		//show_stack(a, "A");
		//show_stack(b, "B");
		if (ac <= 5) // && !is_sort(a, 1))
			sort(&a, &b, &inst, ac - 1);
		else // if (!is_sort(a, 1))
			push_swap(&a, &b, &inst);
		optimize(&inst);
		if (inst)
			ft_printf("%s", inst);
		//show_stack(a, "A");
		//show_stack(b, "B");
	}
	return (0);
}
