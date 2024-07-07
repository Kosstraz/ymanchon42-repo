/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_opti.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:16:13 by bama              #+#    #+#             */
/*   Updated: 2024/07/07 15:31:08 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_op_handle	handle(char *op1, char *op2, char *new)
{
	t_op_handle	ret;

	ret.op1 = op1;
	ret.op2 = op2;
	ret.new = new;
	return (ret);
}

static void	op_modifications(int *op1, int *op2, const t_op_handle h, int *i)
{
	if (*op1 > *op2)
	{
		*i += (*op1 - *op2) * ft_strlen(h.op1);
		*op1 = *op2;
	}
	else
		*op2 = *op1;
	*op1 *= ft_strlen(h.op1);
	*op2 *= ft_strlen(h.op2);
}

static void	opti(char **ops, const t_op_handle h)
{
	int	i;
	int	insert_count;
	int	op1;
	int	op2;

	i = -1;
	while ((*ops)[++i])
	{
		op1 = owsequence(&((*ops)[i]), h.op1);
		op2 = owsequence(&((*ops)[i + op1 * ft_strlen(h.op1)]), h.op2);
		if (op1 != 0 && op2 != 0)
		{
			op_modifications(&op1, &op2, h, &i);
			*ops = strldelete(*ops, i, op1 + op2);
			insert_count = 0;
			while (insert_count++ < (int)(op1 / (int)(ft_strlen(h.op1))))
			{
				*ops = strlinsert(*ops, h.new, i);
				i += ft_strlen(h.new);
			}
		}
		while ((*ops)[i] && (*ops)[i] != '\n')
			i++;
	}
}

void	optimize(char **ops)
{
	int	i;

	if (!ops || !*ops)
		return ;
	i = 0;
	while (i++ < 10)
	{
		opti(ops, handle("ra\n", "rra\n", ""));
		opti(ops, handle("rb\n", "rrb\n", ""));
		opti(ops, handle("rra\n", "ra\n", ""));
		opti(ops, handle("rrb\n", "rb\n", ""));
		opti(ops, handle("pa\n", "pb\n", ""));
		opti(ops, handle("pb\n", "pa\n", ""));
		opti(ops, handle("sa\n", "sb\n", "ss\n"));
		opti(ops, handle("sb\n", "sa\n", "ss\n"));
	}
	while (i++ < 14)
		opti(ops, handle("ra\n", "rb\n", "rr\n"));
	while (i++ < 18)
		opti(ops, handle("rra\n", "rrb\n", "rrr\n"));
	while (i++ < 22)
		opti(ops, handle("rb\n", "ra\n", "rr\n"));
	while (i++ < 26)
		opti(ops, handle("rrb\n", "rra\n", "rrr\n"));
}
