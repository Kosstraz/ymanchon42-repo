/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:00:51 by ymanchon          #+#    #+#             */
/*   Updated: 2024/02/24 12:36:21 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = 0;
		while (base[j])
		{
			if (i != j && base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nb, char *base)
{
	long	n;
	int		size;

	n = (long)nb;
	size = ft_strlen(base);
	if (!ft_check_base(base))
		return ;
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n >= size)
	{
		ft_putnbr_base(n / size, base);
		ft_putchar(base[n % size]);
	}
	else
		ft_putchar(base[n]);
}

/*#include <stdio.h>
int	main(void)
{
	int	i;
	i = 0;
	while (i++ < 1)
	{
		ft_putnbr_base(2147483647, "poneyvif");
		ft_putchar('\n');
	}
}*/
