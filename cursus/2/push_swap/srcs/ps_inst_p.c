/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_inst_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:26:55 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/05 18:33:08 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

inline void	pa(t_stack *b, t_stack *a, char **ops)
{
	*ops = ft_strsjoin(*ops, "pa\n");
	a->len++;
	a->item[a->len - 1] = b->item[b->len - 1];
	b->len--;
	a->item[a->len - 1].i = a->len - 1;
}

inline void	pb(t_stack *a, t_stack *b, char **ops)
{
	*ops = ft_strsjoin(*ops, "pb\n");
	b->len++;
	b->item[b->len - 1] = a->item[a->len - 1];
	a->len--;
	b->item[b->len - 1].i = b->len - 1;
}
