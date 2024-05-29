/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 21:49:27 by ymanchon          #+#    #+#             */
/*   Updated: 2024/05/29 18:57:35 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf(const char *file)
{
	t_vec2	map_size;
	int		valid;
	t_point	*map;

	valid = fdf_file_format(file);
	if (!valid)
		printexit(NO_FDFFILE, 0);
	map = ft_read_fdfmap(file, &map_size);
	free(map);
}

void	draw_line(t_mlx *mlx, t_point a, t_point b, int color)
{
	while (a.x < b.x && b.x < b.y)
		mlx_pixel_put(mlx->mlx, mlx->window, a.x++, a.y++, color);
}

void	draw_square(t_mlx *mlx, t_point *points)
{
	int	i;

	i = 0;
	while (if_point_eq(points[i], NULL_POINT) && if_point_eq(points[i + 1], NULL_POINT))
	{
		draw_line(mlx, points[i], points[i + 1], 0x00FF00FF);
		draw_line(mlx, points[i], points[i + 19], 0x00FFFF00);
	}
}

int	test(t_mlx *mlx)
{
	t_vec2	map_size;
	t_point	*points;

	points = ft_read_fdfmap("maps/42.fdf", &map_size);
	draw_square(mlx, points);
	return (0);
}

int	main(int ac, char **av)
{
	t_mlx	mlx;

	(void)ac;
	(void)av;
	mlx.mlx = mlx_init();
	mlx.window = mlx_new_window(mlx.mlx, 1000, 1000, WINDOW_T);
	mlx_loop_hook(mlx.mlx, &test, &mlx);
	mlx_loop(mlx.mlx);

	mlx_destroy_window(mlx.mlx, mlx.window);
	mlx_destroy_display(mlx.mlx);
	free(mlx.mlx);
	/*if (ac < 2)
		printexit(NO_FILE, 0);
	else if (ac > 2)
		printexit(MANY_FILE, 0);
	else
		fdf(av[1]);*/
	return (0);
}
