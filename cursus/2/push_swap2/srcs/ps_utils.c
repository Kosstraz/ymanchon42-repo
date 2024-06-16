/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:13:46 by ymanchon          #+#    #+#             */
/*   Updated: 2024/06/16 16:36:04 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show_stack(t_stack *a)
{
	while (a->len--)
		ft_printf("a : %d\n", a->s[a->len]);
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

