/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:29:58 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/09 15:34:39 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hooks(int keycode, t_env *env)
{
	if (keycode == MLX_KEY_ESC)
		return (mlx_loop_end(env->mlx));
	if (keycode == MLX_KEY_DOWN)
			env->offset = set_vec2d(env->offset.x, env->offset.y + SPEED);
	if (keycode == MLX_KEY_UP)
		env->offset = set_vec2d(env->offset.x, env->offset.y - SPEED);
	if (keycode == MLX_KEY_LEFT)
		env->offset = set_vec2d(env->offset.x - SPEED, env->offset.y);
	if (keycode == MLX_KEY_RIGHT)
		env->offset = set_vec2d(env->offset.x + SPEED, env->offset.y);
	if (keycode == MLX_KEY_E)
		env->zoom = env->zoom + ZOOM_SPEED;
	if (keycode == MLX_KEY_Q)
		env->zoom = env->zoom - ZOOM_SPEED;
	if (!env->psyche && keycode == MLX_KEY_P)
		env->psyche = 1;
	else if (env->psyche && keycode == MLX_KEY_P)
		env->psyche = 0;
	return (0);
}
