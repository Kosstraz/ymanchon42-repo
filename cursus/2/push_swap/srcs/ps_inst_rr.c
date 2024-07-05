/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_inst_rr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:23:52 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/03 12:04:55 by ymanchon         ###   ########.fr       */
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
		swap(&(s->item[len - 1]), &(s->item[i]));
		i--;
	}
}

inline void	rra(t_stack *a, char **ops)
{
	*ops = ft_strsjoin(*ops, "rra\n");
	rev_r(a);
}

inline void	rrb(t_stack *b, char **ops)
{
	*ops = ft_strsjoin(*ops, "rrb\n");
	rev_r(b);
}

inline void	rrr(t_stack *a, t_stack *b, char **ops)
{
	*ops = ft_strsjoin(*ops, "rrr\n");
	rev_r(a);
	rev_r(b);
}
