/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 18:28:08 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/08 00:52:16 by bama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_env(t_env *env)
{
	env->size = set_vec2i(X_SIZE, Y_SIZE);
	env->mlx = mlx_init();
	if (!env->mlx)
		exit(0);
	env->window = mlx_new_window(env->mlx, env->size.x, env->size.y, TITLE);
	if (!env->window)
		freemexit(0, 1, env->mlx);
}

inline static void	destroy_env(t_env *env)
{
	mlx_clear_window(env->mlx, env->window);
	mlx_destroy_window(env->mlx, env->window);
	mlx_destroy_display(env->mlx);
	free(env->mlx);
}

inline static void	set_hooks(t_env *env)
{
	mlx_key_hook(env->window, key_hooks, env);
	mlx_hook(env->window, WINDOW_CLOSE, MASK_NULL, &mlx_loop_end, env->mlx);
	mlx_loop_hook(env->mlx, &draw, env);
}

inline static void	fractol(t_env *env)
{
	set_hooks(env);
	mlx_loop(env->mlx);
}

int	main(int ac, char **av)
{
	t_env	env;

	if (ac == 1)
		ft_printf(NO_FRACTAL);
	if (ac > 1)
	{
		if (is_valid(av[1], &env))
		{
			init_env(&env);
			fractol(&env);
			destroy_env(&env);
		}
		else
			ft_printf(INVALID_FRACTAL);
	}
	return (0);
}
