/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 22:39:10 by ymanchon          #+#    #+#             */
/*   Updated: 2024/05/29 00:33:08 by ymanchon         ###   ########.fr       */
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

t_vec3	calcul_mapsize(const char *file_path)
{
	t_vec3	ret;
	int		fd;
	char	*line;

	init_vec3(&ret);
	fd = open(file_path, O_RDONLY);
	if (fd <= 0)
		ft_printexit(INVALID_FILE, 0);
	line = get_next_line(fd);
	ret.x = ft_strlen(line) - 1;
	while (line)
	{
		ret.y++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (ret);
}

int	**setmap(int **map)
{
	int	**ret;

	ret = map;
	/*line = get_next_line(fd);
	ret.x = ft_strlen(line) - 1;
	while (line)
	{
		ret.y++;
		free(line);
		line = get_next_line(fd);
	}*/
	return (ret);
}

int	**ft_read_fdfmap(const char *file_path, t_vec3 *map_size)
{
	int		i;
	int		**ret;

	*map_size = calcul_mapsize(file_path);
	ret = (int **)malloc(sizeof(int *) * ((*map_size).y + 1));
	if (!ret)
		ft_printexit(BAD_MALLOC, 1);
	ret[(*map_size).y] = NULL;
	i = 0;
	while (i < (*map_size).y)
	{
		ret[i] = (int *)malloc(sizeof(int) * ((*map_size).x + 1));
		if (!ret[i++])
		{
			freefall((void **)ret, i - 1);
			ft_printexit(BAD_MALLOC, 1);
		}
	}
	ret[i] = NULL;
	return (setmap(ret));
}
