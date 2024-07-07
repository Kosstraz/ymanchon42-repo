/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:25:25 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/07 19:26:50 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

inline t_vec2i	set_vec2i(int x, int y)
{
	t_vec2i	vec2i;

	vec2i.x = x;
	vec2i.y = y;
	return (vec2i);
}

inline t_vec2d	set_vec2d(double x, double y)
{
	t_vec2d	vec2d;

	vec2d.x = x;
	vec2d.y = y;
	return (vec2d);
}
