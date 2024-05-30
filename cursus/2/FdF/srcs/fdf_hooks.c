/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:20:45 by ymanchon          #+#    #+#             */
/*   Updated: 2024/05/30 19:15:44 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_event(t_data *datas)
{
	return (mlx_loop_end(datas->mlx));
}

int	mlx_set_all_hooks(t_data *datas)
{
	mlx_hook(datas->window, 17, 0, &close_event, &datas->mlx);
	mlx_loop_hook(datas->mlx, &fdf_draw_map, datas);
	return (0);
}
