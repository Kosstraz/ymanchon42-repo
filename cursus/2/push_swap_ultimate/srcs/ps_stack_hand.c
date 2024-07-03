/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_hand.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:56:38 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/03 13:25:36 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack)
{
	int	i;

	i = 0;
	stack->len = 0;
	while (i < N)
	{
		stack->item[i].cost = 0;
		stack->item[i].data = 0;
		stack->item[i].i = i;
		i++;
	}
}

void	fill_stack(t_stack *a, int count, char **val)
{
	int	i;

	i = 0;
	a->len = count;
	while (i < count)
	{
		a->item[count - i - 1].data = ft_atoi(val[i]);
		i++;
	}
}

void	show_stack(t_stack stack, const char *name)
{
	int	i;

	i = stack.len - 1;
	ft_printf("-----------\n");
	while (i >= 0)
	{
		ft_printf("%d\t[%d]\n", stack.item[i].data, stack.item[i].i);
		i--;
	}
	ft_printf("-----------\n     %s\n", name);
}
