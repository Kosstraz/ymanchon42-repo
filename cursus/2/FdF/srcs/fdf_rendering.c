/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:37:45 by ymanchon          #+#    #+#             */
/*   Updated: 2024/05/30 19:17:08 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_data *datas, t_point a, t_point b, int color)
{
	int	point;

	if (a.x == b.x && a.y != b.y)
		while (a.y < b.y)
			mlx_pixel_put(datas->mlx, datas->window, a.x, a.y++, color);
	if (a.y == b.y && a.x != b.x)
		while (a.x < b.x)
			mlx_pixel_put(datas->mlx, datas->window, a.x++, a.y, color);
	else
	{
		point = (b.y - b.y) / (b.x - a.x);
		while (a.x < b.x)
			mlx_pixel_put(datas->mlx, datas->window, a.x++, point++, color);
	}
}

int	fdf_draw_map(t_data *datas)
{
	int	i;

	i = 0;
	while (i < datas->point_count - 1)
	{
		ft_printf("test : %d\n", datas->point_count);
		draw_line(datas->mlx, datas->map[i], datas->map[i + 1], RED);
		if (i < datas->point_count - datas->map_size.x)
			draw_line(datas->mlx, datas->map[i], datas->map[i + 20], RED);
		i++;
	}
	return (0);
}
