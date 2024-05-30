/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 22:39:10 by ymanchon          #+#    #+#             */
/*   Updated: 2024/05/30 19:18:07 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	fdf_file_format(const char *file_path)
{
	size_t	i;

	i = ft_strlen(file_path) - 1;
	if (i < 3 || file_path[i] != 'f' || file_path[i - 1] != 'd'
		|| file_path[i - 2] != 'f' || file_path[i - 3] != '.')
		return (0);
	return (1);
}

t_vec2	calcul_mapsize(const char *file_path)
{
	t_vec2	ret;
	int		fd;
	char	*line;

	fd = open(file_path, O_RDONLY);
	if (fd <= 0)
		printexit(INVALID_FILE, 0);
	line = get_next_line(fd);
	ret.x = ft_count_words(line, ' ');
	ret.y = 0;
	while (line)
	{
		ret.y++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (ret);
}

void	atoi_line(t_data *datas, const char *line, int y)
{
	size_t	i;
	t_vec2	*msize;
	int		*pc;
	int		x;
	int		z;

	msize = &datas->map_size;
	pc = &datas->point_count;
	i = 0;
	x = 0;
	while (line[i])
	{
		ft_isspace(line, &i);
		z = ft_atoi(&line[i]);
		i += ft_intlen(z);
		ft_isspace(line, &i);
		add_point(&datas->map[*pc],
			((x * MAPOFFSET) + (WRES_X / 2) - (msize->x * MAPOFFSET) / 2),
			((y * MAPOFFSET) + (WRES_Y / 2) - (msize->y * MAPOFFSET) / 2),
			z);
		(*pc)++;
		x++;
	}
}

t_point	*setmap(t_data *datas, const char *file_path)
{
	int		fd;
	int		y;
	t_point	*map;
	char	*line;

	map = datas->map;
	fd = open(file_path, O_RDONLY);
	line = get_next_line(fd);
	y = 0;
	datas->point_count = 0;
	while (line)
	{
		atoi_line(datas, line, y);
		free(line);
		line = get_next_line(fd);
		y++;
	}
	close(fd);
	return (map);
}

t_point	*ft_read_fdfmap(const char *file_path, t_data *datas)
{
	long	size;

	datas->map_size = calcul_mapsize(file_path);
	size = datas->map_size.x * datas->map_size.y;
	datas->point_count = size;
	datas->map = (t_point *)malloc(sizeof(t_point) * (size + 1));
	if (!datas->map)
		printexit(BAD_MALLOC, 1);
	add_point(&datas->map[size], NULL_POINT, NULL_POINT, NULL_POINT);
	return (setmap(datas, file_path));
}
