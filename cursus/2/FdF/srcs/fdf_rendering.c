/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:37:45 by ymanchon          #+#    #+#             */
/*   Updated: 2024/05/31 18:41:33 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_draw_diag(t_data *datas, t_point a, t_point b, int color)
{
	t_vec2	d;

	d.x = (b.x - a.x);
	d.y = (b.y - a.y);
	if (d.x == d.y)
		while (a.x < b.x && a.y < b.y)
			mlx_pixel_put(datas->mlx, datas->window, a.x++, a.y++, color);
	else
	{
		if (ft_abs(d.y / d.x) > 1)
			fdf_draw_xdiag(datas, a, b, color);
		else if (ft_abs(d.y / d.x) < 1)
			fdf_draw_ydiag(datas, a, b, color);
	}
}

void	fdf_draw_line(t_data *datas, t_point a, t_point b, int color)
{
	if (a.x >= 0 && a.y >= 0
		&& b.x <= WRES_X && b.y <= WRES_Y)
	{
		if (a.x == b.x && a.y != b.y)
			while (a.y < b.y)
				mlx_pixel_put(datas->mlx, datas->window, a.x, a.y++, color);
		if (a.y == b.y && a.x != b.x)
			while (a.x < b.x)
				mlx_pixel_put(datas->mlx, datas->window, a.x++, a.y, color);
		else
			fdf_draw_diag(datas, a, b, color);
	}
}

int	fdf_draw_map(t_data *datas)
{
	int	i;
	int	color;
	int	msizex;

	i = 0;
	while (i < datas->point_count - 1)
	{
		color = datas->map[i].color;
		msizex = datas->map_size.x;
		if (!(i % msizex + 1))
			i++;
		fdf_draw_line(datas, datas->map[i], datas->map[i + 1], color);
		if (i < datas->point_count - msizex)
		{
			color = datas->map[i + msizex].color;
			fdf_draw_line(datas, datas->map[i], datas->map[i + msizex], color);
		}
		i++;
	}
	return (0);
}

/*t_point	*fdf_isometry(t_data *datas)
{
	int		i;
	int		alpha;
	int		beta;
	t_point	p;

	return (NULL);
}*/
