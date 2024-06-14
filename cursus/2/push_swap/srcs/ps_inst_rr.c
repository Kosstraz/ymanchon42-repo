/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_inst_rr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:23:52 by ymanchon          #+#    #+#             */
/*   Updated: 2024/06/13 18:58:42 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_r(t_stack *s)
{
	int	len;
	int	i;

	len = s->len;
	i = len - 2;
	while (i >= 0)
	{
		swap(&(s->s[len - 1]), &(s->s[i]));
		i--;
	}
}

inline void	rra(t_stack *a)
{
	ft_printf("rra\n");
	rev_r(a);
}

inline void	rrb(t_stack *b)
{
	ft_printf("rrb\n");
	rev_r(b);
}

inline void	rrr(t_stack *a, t_stack *b)
{
	ft_printf("rrr\n");
	rra(a);
	rrb(b);
}
