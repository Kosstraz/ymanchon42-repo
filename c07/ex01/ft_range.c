/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:20:21 by ymanchon          #+#    #+#             */
/*   Updated: 2024/02/24 18:04:45 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	i;

	if (max > min)
		return (NULL);
	tab = (int *)malloc(max - min);
	i = 0;
	while (min < max)
		tab[i++] = min++;
	return (tab);
}
