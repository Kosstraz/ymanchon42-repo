/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 20:09:40 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/15 22:15:18 by bama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	ft_isspace(const char *str, size_t *i)
{
	while ((str[*i] >= 9 && str[*i] <= 13) || str[*i] == ' ')
		(*i)++;
	return (*i);
}

static int	ft_is_negative(const char *str, size_t *i)
{
	if (str[*i] == '+' || str[*i] == '-')
		if (str[(*i)++] == '-')
			return (-1);
	return (1);
}

int	ft_atoi(const char *str)
{
	int		ret;
	int		neg;
	size_t	i;

	i = 0;
	ret = 0;
	ft_isspace(str, &i);
	neg = ft_is_negative(str, &i);
	while (str[i] >= '0' && str[i] <= '9')
		ret = ret * 10 + (str[i++] - '0');
	return (ret * neg);
}
