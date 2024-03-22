/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:06:23 by ymanchon          #+#    #+#             */
/*   Updated: 2024/02/21 15:44:45 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str);

int	ft_detect_negativity(char *str, int *idx)
{
	int	ret;
	int	*i;

	ret = 1;
	i = idx;
	while (str[*i])
	{
		if (str[*i] == '-')
			ret *= -1;
		else if (str[*i] != '+')
			return (ret);
		(*i)++;
	}
	return (ret);
}

int	ft_isspace(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int	neg;
	int	ret;
	int	i;

	i = ft_isspace(str);
	neg = ft_detect_negativity(str, &i);
	ret = 0;
	while (str[i] >= '0' && str[i] <= '9')
		ret = ret * 10 + (str[i++] - '0');
	return (ret * neg);
}

/*#include <stdio.h>
int	main(void)
{
	int	i = ft_atoi(" \t\t\n \n \v \r\r  ++--++----2147483648da123");
	printf("%d", i);
	return (0);
}*/
