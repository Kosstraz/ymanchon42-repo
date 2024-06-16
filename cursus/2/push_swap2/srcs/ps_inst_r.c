/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_inst_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:42:59 by ymanchon          #+#    #+#             */
/*   Updated: 2024/06/13 15:26:45 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	r(t_stack *s)
{
	int	len;
	int	i;

	len = s->len;
	i = 1;
	while (i < len)
	{
		swap(&(s->s[0]), &(s->s[i]));
		i++;
	}
}

inline void	ra(t_stack *a)
{
	ft_printf("ra\n");
	r(a);
}

inline void	rb(t_stack *b)
{
	ft_printf("rb\n");
	r(b);
}

inline void	rr(t_stack *a, t_stack *b)
{
	ft_printf("rr\n");
	ra(a);
	rb(b);
}


