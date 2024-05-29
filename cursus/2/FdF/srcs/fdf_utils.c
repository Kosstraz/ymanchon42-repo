/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 23:42:46 by ymanchon          #+#    #+#             */
/*   Updated: 2024/05/29 17:04:07 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

inline void	init_point(t_point *point)
{
	add_point(point, 0, 0, 0);
}

inline void	add_point(t_point *point, int x, int y, int z)
{
	point->x = x;
	point->y = y;
	point->z = z;
}

inline char	if_point_eq(t_point point, int val)
{
	return (point.x == val && point.y == val && point.z == val);
}

inline void	show_points(t_point *points)
{
	int	i;

	i = 0;
	while (!if_point_eq(points[i], NULL_POINT))
	{
		ft_printf("\e[36mpoint %d =>\e[0m\n", i);
		ft_printf("\e[32mx : %d\e[0m\n", points[i].x);
		ft_printf("\e[32my : %d\e[0m\n", points[i].y);
		ft_printf("\e[32mz : %d\e[0m\n", points[i].z);
		ft_printf("\n");
		i++;
	}
}
