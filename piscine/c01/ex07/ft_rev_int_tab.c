/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:06:36 by ymanchon          #+#    #+#             */
/*   Updated: 2024/02/08 12:48:00 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size);

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < (int)(size / 2))
	{
		ft_swap(&(tab[i]), &(tab[(size - i - 1)]));
		i++;
	}
}

/*int main()
{
	const int size = 5;
	int tab[size] = {0, 1, 2, 3, 4};
	int i = 0;
	while (i < size)
		printf("%d, ", tab[i++]);
	printf("\n");
	ft_rev_int_tab(tab, size);
	printf("\n");
	i = 0;
	while (i < size)
		printf("%d, ", tab[i++]);
}*/
