/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:21:32 by ymanchon          #+#    #+#             */
/*   Updated: 2024/02/24 18:03:16 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*malloc(unsigned long size);

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*ret;
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	ret = malloc(sizeof(int) * (max - min));
	if (!ret)
		return (-1);
	i = (min - 1);
	while (++i < max)
		ret[i - min] = i;
	*range = ret;
	return (max - min);
}

/*#include <stdio.h>
int main()
{
	int *tab;
	printf("size of %lu\n", sizeof(int*));
	printf("%d\n", ft_ultimate_range(&tab, 4, 8));
	for (int i = 0; i < 4; i++)
		printf("tab[i] :%d\n", tab[i]);
}*/
