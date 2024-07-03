/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:08:29 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/03 13:38:14 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_swap(t_stack *a, t_stack *b, char **inst)
{
	
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	char	*inst;

	if (ac > 2)
	{
		if (!check_av(ac - 1, &av[1]))
		{	
			ft_printf("Error\n");
			return (0);
		}
		init_stack(&a);
		init_stack(&b);
		fill_stack(&a, ac - 1, &av[1]);
		show_stack(a, "A");
		push_swap(&a, &b, &inst);
		optimize(&inst);
	}
	return (0);
}
