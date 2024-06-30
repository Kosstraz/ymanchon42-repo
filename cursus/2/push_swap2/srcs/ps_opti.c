/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_opti.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:16:13 by bama              #+#    #+#             */
/*   Updated: 2024/06/30 14:05:49 by bama             ###   ########.fr       */
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

/*void	opti(char **ops, t_op_handle h, int size_ops)
{
	int	i;
	int	i_tmp;
	int	opc1;
	int	opc2;

	i = 0;
	opc1 = 0;
	opc2 = 0;
	while ((*ops)[i])
	{
		i_tmp = i;
		opc1 = owsequence_s(&(*ops)[i], h.op1, size_ops - i);
		i += ft_strlen(h.op1) * opc1;
		opc2 = owsequence_s(&(*ops)[i], h.op2, size_ops - i);
		printf("sequence op1 : %d\n", opc1);
		printf("sequence op2 : %d\n", opc2);
		i = i_tmp;
		if (opc2 > 0 && opc1 > opc2)
			i += (opc1 - opc2) * ft_strlen(h.op1);
		if (opc1 > 0 && opc2 > 0)
		{
			strerase(ops, "", i, opc1 * ft_strlen(h.op1)
				+ opc2 * ft_strlen(h.op2));
			strerase(ops, h.new, i, ft_strlen(h.new));
		}
		i++;
	}
}*/

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
			//ft_printf("i1 : %d\ni2 : %d\n", i, i + op1);
			//ft_printf("op1 : %d\nop2 : %d\n", op1, op2);
			if (op1 > op2)
			{
				i += (op1 - op2) * ft_strlen(h.op1);
				op1 = op2;
			}
			else
				op2 = op1;
			op1 *= ft_strlen(h.op1);
			op2 *= ft_strlen(h.op2);
			*ops = strdelete(*ops, i, op1 + op2);
			*ops = strinsert(*ops, h.new, i);
		}
		while ((*ops)[i] && (*ops)[i] != '\n')
			i++;
		i++;
	}
}

void	optimize(char **ops, int size)
{
	opti(ops, handle("rb\n", "rrb\n", ""));
	/*int	i;

	i = 0;
	while (i++ < 5)
	{
		opti(ops, handle("rb\n", "rrb\n", ""), size);
		opti(ops, handle("ra\n", "rra\n", ""), size);
		opti(ops, handle("rrb\n", "rb\n", ""), size);
		opti(ops, handle("rra\n", "ra\n", ""), size);
		opti(ops, handle("rb\n", "ra\n", "rr\n"), size);
		opti(ops, handle("rrb\n", "rra\n", "rrr\n"), size);
		opti(ops, handle("ra\n", "rb\n", "rr\n"), size);
		opti(ops, handle("rra\n", "rrb\n", "rrr\n"), size);
	}*/
}
