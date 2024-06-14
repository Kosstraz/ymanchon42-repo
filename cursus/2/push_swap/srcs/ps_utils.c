/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:13:46 by ymanchon          #+#    #+#             */
/*   Updated: 2024/06/14 15:14:30 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show_stack(t_stack *a)
{
	while (a->len--)
		ft_printf("a : %d\n", a->s[a->len]);
}

int	ps_find_dicho(t_stack *a, int idx)
{
	int	i;

	i = 0;
	while (i <= a->len / 2)
		if (a->s[i++].i == idx)
			return (-1);
	i = a->len - 1;
	while (i > a->len / 2)
		if (a->s[i--].i == idx)
			return (1);
	return (0);
}

int	ps_estimate_dicho(t_stack *a, int idx)
{
	if (a->s[a->len - 2].i == idx && ps_find_dicho(a, idx + 1) < 0)
		return (1);
	return(0);
}
