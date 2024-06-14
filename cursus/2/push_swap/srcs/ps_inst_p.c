/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_inst_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:26:55 by ymanchon          #+#    #+#             */
/*   Updated: 2024/06/13 15:27:12 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

inline void	pa(t_stack *b, t_stack *a)
{
	ft_printf("pa\n");
	a->len++;
	a->s[a->len - 1] = b->s[b->len - 1];
	b->len--;
}

inline void	pb(t_stack *a, t_stack *b)
{
	ft_printf("pb\n");
	b->len++;
	b->s[b->len - 1] = a->s[a->len - 1];
	a->len--;
}
