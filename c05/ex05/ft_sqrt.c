/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:32:44 by ymanchon          #+#    #+#             */
/*   Updated: 2024/02/24 15:49:20 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;
	int	square;

	if (nb > (46340 * 46340) || nb < 1)
		return (0);
	else if (nb == 1)
		return (1);
	i = 1;
	while (i <= (int)(nb / 2))
	{
		square = i * i;
		if (square == nb)
			return (i);
		else if (square > nb)
			return (0);
		i++;
	}
	return (0);
}

/*int	main(void)
{
	printf("%d\n", ft_sqrt(2147483647));
}*/
