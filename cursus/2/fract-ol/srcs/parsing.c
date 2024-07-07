/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 18:48:03 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/07 19:05:15 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// 0 invalid
// 1 valid
char	is_valid(char *name)
{
	if (!ft_strcmp("julia", ft_strtolower(name)))
		return (1);
	else if (!ft_strcmp("mandelbrot", ft_strtolower(name)))
		return (1);
	return (0);
}
