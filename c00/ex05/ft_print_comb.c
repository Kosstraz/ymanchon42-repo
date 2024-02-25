/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:58:13 by ymanchon          #+#    #+#             */
/*   Updated: 2024/02/08 16:10:17 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_trouple(int a, int b, int c)
{
	ft_putchar(a);
	ft_putchar(b);
	ft_putchar(c);
	if (a != '7' || b != '8' || c != '9')
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb(void)
{
	int	a;
	int	b;
	int	c;

	a = '0';
	b = '1';
	c = '2';
	while (a <= '7')
	{
		while (b <= '8')
		{
			while (c <= '9')
			{
				ft_print_trouple(a, b, c);
				c++;
			}
			c = ++b + 1;
		}
		b = ++a;
	}
}

/*int main()
{
	int	e;
	int	a;

	a = 3;

	e = a++;
	//e = a;
	//a += 1;
	ft_putchar(e + '0');
	ft_putchar(' ');
	ft_putchar(a + '0');

	ft_putchar('\n');
	a = 3;

	e = ++a;
	//a += 1;
	//e = a;
	ft_putchar(e + '0');
	ft_putchar(' ');
	ft_putchar(a + '0');

	//ft_print_comb();
}*/
