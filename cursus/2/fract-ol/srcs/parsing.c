/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 18:48:03 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/09 15:53:38 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// 0 invalid
// 1 valid
char	is_valid(char *name, int ac, char **params, t_env *env)
{
	if (!ft_strcmp("julia", ft_strtolower(name)))
	{
		env->fractal_model = Julia;
		if (ac <= 3)
			env->kc = set_vec2d(-0.8, 0.156);
		else
		{
			env->kc.x = ft_atod(params[0]);
			env->kc.y = ft_atod(params[1]);
		}
		return (1);
	}
	else if (!ft_strcmp("mandelbrotvariation", ft_strtolower(name))
		|| !ft_strcmp("mv", ft_strtolower(name)))
	{
		env->fractal_model = Mv;
		return (1);
	}
	else if (!ft_strcmp("mandelbrot", ft_strtolower(name)))
	{
		env->fractal_model = Mandelbrot;
		return (1);
	}
	return (0);
}
