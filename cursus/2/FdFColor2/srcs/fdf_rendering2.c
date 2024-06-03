/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rendering2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:37:45 by ymanchon          #+#    #+#             */
/*   Updated: 2024/06/03 17:38:37 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_draw_xdiag(t_data *datas, t_point a, t_point b)
{
	t_color	color;
	t_vec2	d;
	int		x;
	int		y;

	d.x = (b.x - a.x);
	d.y = (b.y - a.y);
	color = a.color;
	x = a.x;
	y = (x - a.x) * d.y / d.x + a.y;
	while (x < b.x)
	{
		if (x < b.x)
			color = ft_lerpcol(color, b.color, 1.0f / (b.x - x));
		mlx_pixel_put(datas->mlx, datas->window, x, y, color.i);
		y = (x - a.x) * d.y / d.x + a.y;
		x++;
	}
}

void	fdf_draw_ydiag(t_data *datas, t_point a, t_point b)
{
	t_color	color;
	t_vec2	d;
	int		x;
	int		y;

	d.x = (b.x - a.x);
	d.y = (b.y - a.y);
	color = a.color;
	y = a.y;
	x = (y - a.y) * d.y / d.x + a.x;
	while (y < b.y)
	{
		if (y < b.y)
			color = ft_lerpcol(color, b.color, 1.0f / (b.y - y));
		mlx_pixel_put(datas->mlx, datas->window, x, y, color.i);
		y = (y - a.y) * d.y / d.x + a.x;
		y++;
	}
}
