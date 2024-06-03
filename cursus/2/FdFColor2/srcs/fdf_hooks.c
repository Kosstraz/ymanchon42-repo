/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:20:45 by ymanchon          #+#    #+#             */
/*   Updated: 2024/05/31 11:45:52 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_event(t_data *datas)
{
	return (mlx_loop_end(datas->mlx));
}

int	handle_key(int keycode, t_data *datas)
{
	if (keycode == FKEY_ESC)
		return (mlx_loop_end(datas->mlx));
	return (0);
}

int	mlx_set_all_hooks(t_data *datas)
{
	mlx_hook(datas->window, WINDOW_CLOSE, MASK_NULL, &close_event, datas);
	mlx_hook(datas->window, ON_KEYDOWN, MASK_KEYPRESS, &handle_key, datas);
	mlx_loop_hook(datas->mlx, &fdf_draw_map, datas);
	return (0);
}
