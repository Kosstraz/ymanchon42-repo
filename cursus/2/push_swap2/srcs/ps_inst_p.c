/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_inst_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:26:55 by ymanchon          #+#    #+#             */
/*   Updated: 2024/06/18 12:40:06 by bama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

inline void	pa(t_stack *b, t_stack *a, char **ops)
{
	*ops = ft_strsjoin(*ops, "pa\n");
	a->len++;
	a->s[a->len - 1] = b->s[b->len - 1];
	b->len--;
}

inline void	pb(t_stack *a, t_stack *b, char **ops)
{
	*ops = ft_strsjoin(*ops, "pb\n");
	b->len++;
	b->s[b->len - 1] = a->s[a->len - 1];
	a->len--;
}
