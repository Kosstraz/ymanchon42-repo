/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 23:42:46 by ymanchon          #+#    #+#             */
/*   Updated: 2024/05/31 20:52:19 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

inline int	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

inline t_color	ft_lerpcol(t_color a, t_color b, float t)
{
	t_color	ret;

	ret.r = ft_lerp(a.r, b.r, t);
	ret.g = ft_lerp(a.g, b.g, t);
	ret.b = ft_lerp(a.b, b.b, t);
	ret.i = color_to_int(ret);
	return (ret);
}

inline float	ft_lerp(int a, int b, float t)
{
	if (b < a)
		return ((1.0f - t) * b + t * a);
	return ((1.0f - t) * a + t * b);
}

t_color	int_to_color(unsigned int col)
{
	t_color	ret;

	ret.b = (0x0000FF & col);
	ret.g = (0x00FF00 & col) >> 8;
	ret.r = (0xFF0000 & col) >> 16;
	ret.i = col;
	return (ret);
}

unsigned int	color_to_int(t_color col)
{
	return ((0x0000FF & col.b)
		| (((0x0000FF) & col.g) << 8)
		| (((0x0000FF) & col.r) << 16));
}
