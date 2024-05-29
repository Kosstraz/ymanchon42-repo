/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 22:39:10 by ymanchon          #+#    #+#             */
/*   Updated: 2024/05/29 17:38:42 by ymanchon         ###   ########.fr       */
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

t_point	*atoi_line(const char *line, t_point *tabY, int y, int *pt_count)
{
	size_t	i;
	int		x;
	int		value;

	i = 0;
	x = 0;
	while (line[i])
	{
		ft_isspace(line, &i);
		value = ft_atoi(&line[i]);
		i += ft_intlen(value);
		ft_isspace(line, &i);
		add_point(&tabY[*pt_count], x, y, value);
		(*pt_count)++;
		x++;
	}
	return (tabY);
}

t_point	*setmap(t_point *map, const char *file_path)
{
	int		fd;
	int		y;
	int		pt_count;
	t_point	*ret;
	char	*line;

	ret = map;
	fd = open(file_path, O_RDONLY);
	line = get_next_line(fd);
	y = 0;
	pt_count = 0;
	while (line)
	{
		ret = atoi_line(line, ret, y, &pt_count);
		free(line);
		line = get_next_line(fd);
		y++;
	}
	close(fd);
	return (ret);
}

t_point	*ft_read_fdfmap(const char *file_path, t_vec2 *map_size)
{
	long	size;
	t_point	*map;

	*map_size = calcul_mapsize(file_path);
	size = map_size->x * map_size->y;
	map = (t_point *)malloc(sizeof(t_point) * (size + 1));
	if (!map)
		printexit(BAD_MALLOC, 1);
	add_point(&map[size], NULL_POINT, NULL_POINT, NULL_POINT);
	return (setmap(map, file_path));
}
