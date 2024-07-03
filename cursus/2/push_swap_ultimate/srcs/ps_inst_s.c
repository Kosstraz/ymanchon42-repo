/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_inst_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:03:04 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/03 12:06:13 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

inline void	swap(t_item *s1, t_item *s2)
{
	s1->data ^= s2->data;
	s2->data ^= s1->data;
	s1->data ^= s2->data;
	s1->cost ^= s2->cost;
	s2->cost ^= s1->cost;
	s1->cost ^= s2->cost;
	s1->i ^= s2->i;
	s2->i ^= s1->i;
	s1->i ^= s2->i;
}

inline static void	s(t_stack *s, int len)
{
	swap(&(s->item[len - 1]), &(s->item[len - 2]));
}

inline void	sa(t_stack *a, char **ops)
{
	*ops = ft_strsjoin(*ops, "sa\n");
	s(a, a->len);
}

inline void	sb(t_stack *b, char **ops)
{
	*ops = ft_strsjoin(*ops, "sb\n");
	s(b, b->len);
}

inline void	ss(t_stack *a, t_stack *b, char **ops)
{
	*ops = ft_strsjoin(*ops, "ss\n");
	s(a, a->len);
	s(b, b->len);
}
