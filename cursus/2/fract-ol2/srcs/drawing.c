/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:35:50 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/08 01:07:52 by bama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// @param complex Nombre complexe --> (RE, IM)
static int	julia(t_vec2i pos, t_vec2d complex)
{
	double  z_re;
    double  z_im;
    double  z_re2;
    double  z_im2;
    int n;

    z_re = pos.x;
    z_im = pos.y;
    n = 0;
    while (n < PRECISION)
    {
        z_re2 = z_re * z_re;
        z_im2 = z_im * z_im;
        if (z_re2 + z_im2 > 4.0)
            break ;
        z_im = 2 * z_re * z_im + complex.y;
        z_re = z_re2 - z_im2 + complex.x;
        n++;
    }
    return (n);
}

// @param complex Nombre complexe --> (RE, IM)
static int	mandelbrot(t_vec2i pos, t_vec2d complex)
{
	double  z_re;
    double  z_im;
    double  z_re2;
    double  z_im2;
    int n;

    (void)pos;
    z_re = complex.x;
    z_im = complex.y;
    n = 0;
    while (n < PRECISION)
    {
        z_re2 = z_re * z_re;
        z_im2 = z_im * z_im;
        if (z_re2 + z_im2 > 4.0)
            break ;
        z_im = 2 * z_re * z_im + complex.y;
        z_re = z_re2 - z_im2 + complex.x;
        n++;
    }
    return (n);
}

static void draw_fractal(t_env *env, int (*fractal_func)(t_vec2i, t_vec2d))
{
    //int     color;
    int     n;
    double  re;
    double  im;
    t_vec2i pos;

    pos.x = 0;
    pos.y = 0;
    while (pos.x < X_SIZE)
    {
        while (pos.y < Y_SIZE)
        {
            re = (pos.x - X_SIZE / 2.0) * 4.0 / X_SIZE;
            im = (pos.y - Y_SIZE / 2.0) * 4.0 / Y_SIZE;
            n = fractal_func(set_vec2i(pos.x, pos.y), set_vec2d(re, im));
            int color = n == PRECISION ? 0x0000FF : 0x00FF00;//(n * 255 / PRECISION) << 16 | (n * 255 / PRECISION) << 8 | (n * 255 / PRECISION);
            mlx_pixel_put(env->mlx, env->window, pos.x, pos.y, color);
            pos.y++;
        }
        pos.x++;
    }
}

int	draw(t_env *env)
{
	if (env->fractal_model == Julia)
		draw_fractal(env, julia);
    else if (env->fractal_model == Mandelbrot)
	{
    	draw_fractal(env, mandelbrot);
	}
    return (0);
}
