/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:29:58 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/07 19:32:40 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hooks(int keycode, t_env *env)
{
	if (keycode == MLX_KEY_ESC)
		return (mlx_loop_end(env->mlx));
	return (0);
}
