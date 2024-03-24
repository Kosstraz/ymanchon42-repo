/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:09:33 by ymanchon          #+#    #+#             */
/*   Updated: 2024/03/18 15:09:34 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_libprintf.h"
#include <stdlib.h>
#include <stdio.h>

static char	*ft_szero()
{
	char	*ret;

	ret = (char *)malloc(2);
	if (!ret)
		return (NULL);
	ret[0] = '0';
	ret[1] = '\0';
	return (ret);
}

static char	*ft_ith_pos(unsigned int n, const char *base)
{
	char	*res;
	int		i;

	res = (char *)malloc(sizeof(int) * 2 + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (n > 0)
	{
		res[i++] = base[n % 16];
		n /= 16;
	}
	res[i--] = '\0';
	ft_swapchr(&res, i);
	return (res);
}

static int	inv_bin(unsigned int n)
{
	return (n ^ 0xFFFFFFFF);
}

char	*ft_ith(int n, const char *base)
{
	if (n > 0)
		return (ft_ith_pos(n, base));
	else if (n < 0)
		return (ft_ith_pos(-inv_bin(n) - 1, base));
	else
		return (ft_szero());
}