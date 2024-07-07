/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:26:35 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/07 13:55:12 by ymanchon         ###   ########.fr       */
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
	int		i;
	size_t	j;
	size_t	size;
	size_t	start;
	int		sign;

	i = -1;
	while (++i < ac)
	{
		sign = 0;
		j = 0;
		size = ft_strlen(av[i]);
		ft_isspace(av[i], &j);
		start = j--;
		while (++j < size)
		{
			if (!sign && start == j && (av[i][j] == '-' || av[i][j] == '+'))
				sign = 1;
			else if (((sign || (!sign && start != j))
					&& (av[i][j] == '-' || av[i][j] == '+'))
					|| !is_respectful(av[i][j]))
				return (0);
		}
	}
	return (1);
}

// 0 exist
// 1 no
char	is_exist(int digits[], int integer, int count)
{
	int	i;

	i = 0;
	while (i < count)
		if (integer == digits[i++])
			return (1);
	return (0);
}

// 0 single
// 1 same
char	same_digit(const int ac, char **av)
{
	int	i;
	int	integer;
	int	digits[N];

	i = 0;
	while (i < ac)
	{
		integer = ft_atoi(av[i]);
		if (is_exist(digits, integer, i))
			return (1);
		digits[i++] = integer;
	}
	return (0);
}
