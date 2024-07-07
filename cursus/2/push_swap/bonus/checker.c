/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:54:45 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/07 17:23:07 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

// 0 no sorted
// 1 sorted
static char	is_sorted(const t_stack a)
{
	int	i;
	int	j;

	i = 0;
	while (i < a.len - 1)
	{
		j = i + 1;
		while (j < a.len)
		{
			if (a.item[i].data < a.item[j].data)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

// 0 incorrect
// 1 correct
static char	apply_instructions(t_stack *a, t_stack *b, char **inst)
{
	if (!ft_strcmp("pa\n", *inst))
		pa(b, a, inst);
	else if (!ft_strcmp("pb\n", *inst))
		pb(a, b, inst);
	else if (!ft_strcmp("ra\n", *inst))
		ra(a, inst);
	else if (!ft_strcmp("rb\n", *inst))
		rb(b, inst);
	else if (!ft_strcmp("rra\n", *inst))
		rra(a, inst);
	else if (!ft_strcmp("rrb\n", *inst))
		rrb(b, inst);
	else if (!ft_strcmp("rr\n", *inst))
		rr(a, b, inst);
	else if (!ft_strcmp("rrr\n", *inst))
		rrr(a, b, inst);
	else if (!ft_strcmp("sa\n", *inst))
		sa(a, inst);
	else if (!ft_strcmp("sb\n", *inst))
		sb(b, inst);
	else if (!ft_strcmp("ss\n", *inst))
		ss(a, b, inst);
	else
		return (0);
	return (1);
}

// 0 incorrect
// 1 correct
static void	read_instructions(t_stack *a, t_stack *b)
{
	char	*gnl;

	gnl = get_next_line(1);
	while (gnl)
	{
		if (!apply_instructions(a, b, &gnl))
		{
			free(gnl);
			write(2, "Error\n", 7);
			exit(0);
		}
		free(gnl);
		gnl = get_next_line(1);
	}
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac >= 2 && ac <= N + 1)
	{
		if (!check_av(ac - 1, &av[1]) || same_digit(ac - 1, &av[1]))
		{	
			write(2, "Error\n", 7);
			return (0);
		}
		init_stack(&a);
		init_stack(&b);
		fill_stack(&a, ac - 1, &av[1]);
		read_instructions(&a, &b);
		if (is_sorted(a) && b.len == 0)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	return (0);
}
