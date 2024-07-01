/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_opti.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:16:13 by bama              #+#    #+#             */
/*   Updated: 2024/07/01 16:04:38 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_op_handle	handle(char *op1, char *op2, char *new)
{
	t_op_handle	ret;

	ret.op1 = op1;
	ret.op2 = op2;
	ret.new = new;
	return (ret);
}

static void	opti(char **ops, t_op_handle h)
{
	int	i;
	int	op1;
	int	op2;

	i = 0;
	while ((*ops)[i])
	{
		op1 = owsequence(&((*ops)[i]), h.op1);
		op2 = owsequence(&((*ops)[i + op1 * ft_strlen(h.op1)]), h.op2);
		if (op1 != 0 && op2 != 0)
		{
			if (op1 > op2)
			{
				i += (op1 - op2) * ft_strlen(h.op1);
				op1 = op2;
			}
			else
				op2 = op1;
			op1 *= ft_strlen(h.op1);
			op2 *= ft_strlen(h.op2);
			*ops = strldelete(*ops, i, op1 + op2);
			*ops = strlinsert(*ops, h.new, i);
		}
		while ((*ops)[i] && (*ops)[i] != '\n')
			i++;
		i++;
	}
}

void	optimize(char **ops)
{
	int	i;

	i = 0;
	while (i++ < 3)
	{
		opti(ops, handle("rb\n", "rrb\n", ""));
		opti(ops, handle("ra\n", "rra\n", ""));
		opti(ops, handle("rrb\n", "rb\n", ""));
		opti(ops, handle("rra\n", "ra\n", ""));
		opti(ops, handle("ra\n", "rb\n", "rr\n"));
		opti(ops, handle("rb\n", "ra\n", "rr\n"));
		opti(ops, handle("rra\n", "rrb\n", "rrr\n"));
		opti(ops, handle("rrb\n", "rra\n", "rrr\n"));
		opti(ops, handle("sa\n", "sb\n", "ss\n"));
		opti(ops, handle("sa\n", "sb\n", "ss\n"));
	}
}
