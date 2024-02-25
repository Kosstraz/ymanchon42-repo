/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:27:57 by ymanchon          #+#    #+#             */
/*   Updated: 2024/02/24 17:26:12 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	ret;
	int	i;

	ret = 1;
	i = 2;
	if (nb == 0)
		return (1);
	if (nb < 1)
		return (0);
	while (i <= nb)
		ret *= i++;
	return (ret);
}

/*int	main(void)
{
	printf("%d\n", ft_iterative_factorial(10));
	return (0);
}*/
