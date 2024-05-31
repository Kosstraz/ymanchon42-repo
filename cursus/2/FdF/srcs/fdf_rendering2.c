/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rendering2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:37:45 by ymanchon          #+#    #+#             */
/*   Updated: 2024/05/31 15:29:41 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_draw_xdiag(t_data *datas, t_point a, t_point b, int color)
{
	t_vec2	d;
	int		x;
	int		y;

	x = a.x;
	y = (x - a.x) * d.y / d.x + a.y;
	while (x < b.x)
	{
		mlx_pixel_put(datas->mlx, datas->window, x, y, color);
		y = (x - a.x) * d.y / d.x + a.y;
		x++;
	}
}

void	fdf_draw_ydiag(t_data *datas, t_point a, t_point b, int color)
{
	t_vec2	d;
	int		x;
	int		y;

	y = a.y;
	x = (y - a.y) * d.y / d.x + a.x;
	while (y < b.y)
	{
		mlx_pixel_put(datas->mlx, datas->window, x, y, color);
		y = (y - a.y) * d.y / d.x + a.x;
		y++;
	}
}
