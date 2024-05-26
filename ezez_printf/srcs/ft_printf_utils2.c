/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:09:20 by ymanchon          #+#    #+#             */
/*   Updated: 2024/05/26 20:01:00 by ymanchon         ###   ########.fr       */
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

int	ft_putunbr(unsigned int n, int len)
{
	if (n == 0)
		return (ft_putchar('0'));
	else if (n >= 10)
	{
		ft_putunbr(n / 10, len);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n + '0');
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_toupper(char *s)
{
	size_t	i;

	i = -1;
	while (s[++i])
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] -= 32;
	return (s);
}