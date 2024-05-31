/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 21:49:27 by ymanchon          #+#    #+#             */
/*   Updated: 2024/05/31 18:02:52 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf(const char *file)
{
	int		valid;
	t_data	datas;

	valid = fdf_file_format(file);
	if (!valid)
		printexit(NO_FDFFILE, 0);
	datas.map = ft_read_fdfmap(file, &datas);
	datas.mlx = mlx_init();
	datas.window = mlx_new_window(datas.mlx, WRES_X, WRES_Y, WTITLE);
	mlx_set_all_hooks(&datas);
	mlx_loop(datas.mlx);
	mlx_destroy_window(datas.mlx, datas.window);
	mlx_destroy_display(datas.mlx);
	free(datas.mlx);
	free(datas.map);
}

int	main(int ac, char **av)
{
	if (ac < 2)
		printexit(NO_FILE, 0);
	else if (ac > 2)
		printexit(MANY_FILE, 0);
	else
		fdf(av[1]);
	return (0);
}
