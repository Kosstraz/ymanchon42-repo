/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:09:20 by ymanchon          #+#    #+#             */
/*   Updated: 2024/05/16 16:26:09 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft_printf.h"

void	ft_swapchr(char **str, unsigned long size)
{
	unsigned long	j;

	j = 0;
	while (size > j)
	{
		(*str)[size] ^= (*str)[j];
		(*str)[j] ^= (*str)[size];
		(*str)[size--] ^= (*str)[j++];
	}
}

void	ft_putunbr(unsigned int n)
{
	if (n == 0)
		ft_putchar('0');
	else if (n >= 10)
	{
		ft_putunbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n + '0');
}
