/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 18:48:03 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/08 00:16:11 by bama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// 0 invalid
// 1 valid
char	is_valid(char *name, t_env *env)
{
	if (!ft_strcmp("julia", ft_strtolower(name)))
	{
		env->fractal_model = Julia;
		return (1);
	}
	else if (!ft_strcmp("mandelbrot", ft_strtolower(name)))
	{
		env->fractal_model = Mandelbrot;
		return (1);
	}
	return (0);
}
