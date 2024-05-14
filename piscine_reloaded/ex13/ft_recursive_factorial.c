/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:34:55 by ymanchon          #+#    #+#             */
/*   Updated: 2024/02/24 17:24:38 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	ret;

	ret = 1;
	if (nb == 0)
		return (1);
	if (nb < 1)
		return (0);
	return (nb * ft_recursive_factorial(nb - 1));
}

/*#include <stdio.h>
int	main(void)
{
	printf("%d", ft_recursive_factorial(5));
}*/
