/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:09:20 by ymanchon          #+#    #+#             */
/*   Updated: 2024/03/18 15:09:22 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_libprintf.h"

void		ft_swapchr(char **str, unsigned long size)
{
	unsigned long	j;
	unsigned long	tmp;

	j = 0;
	while (size > j)
	{
		tmp = (*str)[size];
		(*str)[size] = (*str)[j];
		(*str)[j] = tmp;
		size--;
		j++;
	}
}