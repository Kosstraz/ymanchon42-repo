/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 10:15:43 by ymanchon          #+#    #+#             */
/*   Updated: 2024/02/11 17:34:28 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int	between(int n, int min, int max)
{
	if (n > min && n < max)
		return (1);
	return (0);
}

void	draw_element(int i, int j, int x, int y)
{
	if ((i == 0 && j == 0) || (i == x && j == y))
		ft_putchar('A');
	else if ((i == 0 && j == y) || (i == x && j == 0))
		ft_putchar('C');
	else if (between(i, 0, x) && (j == 0 || j == y))
		ft_putchar('B');
	else if (between(j, 0, y) && (i == 0 || i == x))
		ft_putchar('B');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	i;
	int	j;

	x--;
	y--;
	j = 0;
	while (j <= y)
	{
		i = 0;
		while (i <= x)
		{
			draw_element(i, j, x, y);
			i++;	
		}
		ft_putchar('\n');
		j++;
	}
}
