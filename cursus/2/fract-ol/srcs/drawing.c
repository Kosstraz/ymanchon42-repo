/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:35:50 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/09 15:50:48 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// @param complex Nombre complexe --> (RE, IM)
static int	julia(t_env *env, t_vec2d pos)
{
	int		i;
	double	tmp;
	t_vec2d	z;
	t_vec2d	c;

	z.x = (((pos.x - (X_SIZE / 2)) / (X_SIZE / 4)) / env->zoom) + env->offset.x;
	z.y = (((pos.y - (Y_SIZE / 2)) / (Y_SIZE / 4)) / env->zoom) + env->offset.y;
	c.x = env->kc.x;
	c.y = env->kc.y;
	i = 0;
	while (i < PRECISION)
	{
		tmp = z.x * z.x - z.y * z.y + c.x;
		z.y = 2 * z.x * z.y + c.y;
		z.x = tmp;
		if (z.x * z.x - z.y * z.y + c.x > 4.0)
			return (i);
		i++;
	}
	return (i);
}

// @param complex Nombre complexe --> (RE, IM)
static int	mandelbrot(t_env *env, t_vec2d pos)
{
	int		i;
	double	tmp;
	t_vec2d	z;
	t_vec2d	c;

	z.x = 0.0;
	z.y = 0.0;
	c.x = ((pos.x - (X_SIZE / 2)) / (X_SIZE / 4) / env->zoom) + env->offset.x;
	c.y = ((pos.y - (Y_SIZE / 2)) / (Y_SIZE / 3) / env->zoom) + env->offset.y;
	i = 0;
	while (i < PRECISION)
	{
		tmp = z.x * z.x - z.y * z.y + c.x;
		z.y = 2 * z.x * z.y + c.y;
		z.x = tmp;
		if (z.x * z.x - z.y * z.y + c.x > 4.0)
			return (i);
		i++;
	}
	return (i);
}

// @param complex Nombre complexe --> (RE, IM)
static int	mandelbrot_variation(t_env *env, t_vec2d pos)
{
	int		i;
	double	tmp;
	t_vec2d	z;
	t_vec2d	c;

	z.x = 0.0;
	z.y = 0.0;
	c.x = ((pos.x - (X_SIZE / 2)) / (X_SIZE / 4) / env->zoom) + env->offset.x;
	c.y = ((pos.y - (Y_SIZE / 2)) / (Y_SIZE / 3) / env->zoom) + env->offset.y;
	i = 0;
	while (i < PRECISION)
	{
		tmp = ft_absd(z.x * z.x - z.y * z.y) + c.x;
		z.y = 2 * z.x * z.y + c.y;
		z.x = tmp;
		if (z.x * z.x - z.y * z.y + c.x > 4.0)
			return (i);
		i++;
	}
	return (i);
}

static void	draw_fractal(t_env *env, int (*fractal_func)(t_env *, t_vec2d))
{
	t_vec2i	coords;
	int		precision;
	int		color;
	int		i;

	i = 0;
	coords.y = 0;
	while (coords.y < Y_SIZE)
	{
		coords.x = 0;
		while (coords.x < X_SIZE)
		{
			precision = fractal_func(env, set_vec2d(coords.x, coords.y));
			color = ((precision << 16) | (precision << 8) | (precision << 4)
					| precision);
			if (env->psyche)
				color <<= (color * i * i);
			else if (!env->psyche && env->zoom != 1)
				color *= ((int)env->zoom << 4 | (int)env->zoom) << 1;
			put_pixel_on_image(env, coords.x, coords.y, color);
			i++;
			coords.x++;
		}
		coords.y++;
	}
}

int	draw(t_env *env)
{
	if (env->fractal_model == Mandelbrot)
		draw_fractal(env, mandelbrot);
	else if (env->fractal_model == Julia)
		draw_fractal(env, julia);
	else if (env->fractal_model == Mv)
		draw_fractal(env, mandelbrot_variation);
	mlx_put_image_to_window(env->mlx, env->window, env->image.v, 0, 0);
	return (0);
}
