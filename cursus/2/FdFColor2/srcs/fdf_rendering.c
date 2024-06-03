/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:37:45 by ymanchon          #+#    #+#             */
/*   Updated: 2024/06/03 17:14:15 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_draw_diag(t_data *datas, t_point a, t_point b)
{
	t_vec2	d;
	t_color	color;

	d.x = (b.x - a.x);
	d.y = (b.y - a.y);
	if (d.x == d.y)
	{
		color = a.color;
		while (a.x < b.x && a.y < b.y)
		{
			color = ft_lerpcol(color, b.color, 1.0f / (b.x - a.x));
			mlx_pixel_put(datas->mlx, datas->window, a.x++, a.y++, color.i);
		}
	}
	else
	{
		if (ft_abs(d.y / d.x) > 1)
			fdf_draw_xdiag(datas, a, b);
		else if (ft_abs(d.y / d.x) < 1)
			fdf_draw_ydiag(datas, a, b);
	}
}

void	fdf_draw_line(t_data *datas, t_point a, t_point b)
{
	t_color	color;

	color = a.color;
	if (a.x >= 0 && a.y >= 0 && b.x <= WRES_X && b.y <= WRES_Y)
	{
		if (a.x == b.x && a.y != b.y)
		{
			while (a.y < b.y)
			{
				color = ft_lerpcol(color, b.color, 1.0f / (b.y - a.y));
				mlx_pixel_put(datas->mlx, datas->window, a.x, a.y++, color.i);
			}
		}
		if (a.y == b.y && a.x != b.x)
		{
			while (a.x < b.x)
			{
				color = ft_lerpcol(color, b.color, 1.0f / (b.x - a.x));
				mlx_pixel_put(datas->mlx, datas->window, a.x++, a.y, color.i);
			}
		}
		else
			fdf_draw_diag(datas, a, b);
	}
}

int	fdf_draw_map(t_data *datas)
{
	int	i;
	int	msizex;

	i = 0;
	while (i < datas->point_count - 1)
	{
		msizex = datas->map_size.x;
		if (!(i % msizex + 1))
			i++;
		fdf_draw_line(datas, datas->map[i], datas->map[i + 1]);
		if (i < datas->point_count - msizex)
			fdf_draw_line(datas, datas->map[i], datas->map[i + msizex]);
		i++;
	}
	return (0);
}

t_point	*fdf_isometry(t_data *datas)
{
	/*int	i;

	i = 0;
	while (i < datas->point_count)
	{
		datas->map[i].x *= sin(PI / 6);
		datas->map[i].y *= cos(PI / 6);
		i++;
	}*/
	return (datas->map);
}
