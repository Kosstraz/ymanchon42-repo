/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 21:49:27 by ymanchon          #+#    #+#             */
/*   Updated: 2024/05/29 00:32:14 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf(const char *file)
{
	int		valid;
	t_vec3	map_size;
	char	**map;

	valid = fdf_file_format(file);
	if (!valid)
		ft_printexit(NO_FDFFILE, 0);
	map = ft_read_fdfmap(file, &map_size);
	freefall((void **)map, map_size.y);
}

int	main(int ac, char **av)
{
	if (ac < 2)
		ft_printexit(NO_FILE, 0);
	else if (ac > 2)
		ft_printexit(MANY_FILE, 0);
	else
		fdf(av[1]);
	return (0);
}
