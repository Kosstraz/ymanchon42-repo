/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:26:35 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/03 13:35:17 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 0 error
// 1 success
static char	is_respectful(char c)
{
	return (ft_isdigit(c) || c == '-' || c == '+');
}

// 0 error
// 1 success
char	check_av(int ac, char **av)
{
	int	i;
	int	j;
	int	size;
	int	neg;

	i = 0;
	neg = 0;
	while (i < ac)
	{
		j = 0;
		size = ft_strlen(av[i]);
		while (j < size)
		{
			if (!neg && is_respectful(av[i][j]))
				neg = 1;
			else if (!is_respectful(av[i][j]))
				return (0);
			else if (neg && (av[i][j] == '-' || av[i][j] == '+'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
