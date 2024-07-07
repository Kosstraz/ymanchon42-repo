/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bama <bama@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 18:34:41 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/08 01:02:09 by bama             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"

# define NO_FRACTAL "\e[1;31mVeuillez saisir un nom de fractale valide :)\e[0;2;31m\n\
Voici les differentes fractales valides :\e[2;31m\n\
1) \e[0;31mJulia\e[0;2;31m\n\
2) \e[0;31mMandelbrot\e[2;31m\n\e[0m"

# define INVALID_FRACTAL "\e[1;31mCette fractale est invalide :(\e[0;2;31m\n\
Voici les differentes fractales valides :\e[2;31m\n\
1) \e[0;31mJulia\e[0;2;31m\n\
2) \e[0;31mMandelbrot\e[2;31m\n\e[0m"

# define TITLE "FRACTOL !!"

# define X_SIZE 900
# define Y_SIZE 600

# define PRECISION 1000

# define MLX_KEY_ESC 65307

# define WINDOW_CLOSE 17

# define MASK_NULL 0

typedef enum e_fractal
{
	Julia,
	Mandelbrot
}	t_e_fractal;

// vector2 <int>
// (x, y)
typedef struct s_vec2i
{
	int	x;
	int	y;
}	t_vec2i;

// vector2 <double>
// (x, y)
typedef struct s_vec2d
{
	double	x;
	double	y;
}	t_vec2d;

typedef struct s_env
{
	void		*mlx;
	void		*window;
	t_vec2i		size;
	t_e_fractal	fractal_model;
}	t_env;

char	is_valid(char *name, t_env *env);
int		draw(t_env *env);
int		key_hooks(int keycode, t_env *env);
t_vec2i	set_vec2i(int x, int y);
t_vec2d	set_vec2d(double x, double y);

#endif