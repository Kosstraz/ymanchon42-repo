/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_inst_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:03:04 by ymanchon          #+#    #+#             */
/*   Updated: 2024/06/16 16:10:20 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

inline void	swap(t_items *s1, t_items *s2)
{
	s1->data ^= s2->data;
	s2->data ^= s1->data;
	s1->data ^= s2->data;
	s1->target ^= s2->target;
	s2->target ^= s1->target;
	s1->target ^= s2->target;
}

inline static void	s(t_stack *s, int len)
{
	swap(&(s->s[len - 1]), &(s->s[len - 2]));
}

inline void	sa(t_stack *a)
{
	ft_printf("sa\n");
	s(a, a->len);
}

inline void	sb(t_stack *b)
{
	ft_printf("sb\n");
	s(b, b->len);
}

inline void	ss(t_stack *a, t_stack *b)
{
	ft_printf("ss\n");
	s(a, a->len);
	s(b, b->len);
}
