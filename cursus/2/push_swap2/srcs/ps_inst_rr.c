/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_inst_rr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:23:52 by ymanchon          #+#    #+#             */
/*   Updated: 2024/06/18 12:40:18 by bama             ###   ########.fr       */
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
