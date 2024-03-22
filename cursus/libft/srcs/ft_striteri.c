/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 20:10:39 by ymanchon          #+#    #+#             */
/*   Updated: 2024/03/18 20:10:40 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	t_striteri(char *str, void (*f)(unsigned int, char *))
{
	unsigned int		i;

	i = 0;
	while (str[i++])
		f(i, &(str[i - 1]));
}