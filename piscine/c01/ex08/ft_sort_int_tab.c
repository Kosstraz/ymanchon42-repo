/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:34:19 by ymanchon          #+#    #+#             */
/*   Updated: 2024/02/09 10:37:30 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size);

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1)
		{
			if (tab[j + 1] < tab[j])
				ft_swap(&tab[j + 1], &tab[j]);
			j++;
		}
		i++;
	}
}

/*int main(void)
{
	const int size = 5;
	int tab[size] = {3, 1, 2, 0, 4};
	int i = 0;
	while (i < size)
		printf("%d, ", tab[i++]);
	ft_sort_int_tab(tab, size);
	printf("\n");
	i = 0;
	while (i < size)
		printf("%d, ", tab[i++]);
}*/
