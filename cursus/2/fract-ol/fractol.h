/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 18:34:41 by ymanchon          #+#    #+#             */
/*   Updated: 2024/07/09 15:34:25 by ymanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"

# define NO_FRACTAL "\e[1;31mVeuillez saisir un nom de fractale valide :)\e[0;2;31m\n\
Voici les differentes fractales valides :\e[2;31m\n\
1) \e[0;31mJulia\e[0;2;31m\n\
2) \e[0;31mMandelbrot\e[2;31m\n\
3) \e[0;31mMandelbrotVariation (mv)\e[2;31m\n\e[0m"

# define INVALID_FRACTAL "\e[1;31mCette fractale est invalide :(\e[0;2;31m\n\
Voici les differentes fractales valides :\e[2;31m\n\
1) \e[0;31mJulia\e[0;2;31m\n\
2) \e[0;31mMandelbrot\e[2;31m\n\
3) \e[0;31mMandelbrotVariation (mv)\e[2;31m\n\e[0m"

# define TITLE "FRACTOL !!"

# define X_SIZE 900
# define Y_SIZE 600

# define PRECISION 50

# define MLX_KEY_ESC 65307
# define MLX_KEY_LEFT 65361
# define MLX_KEY_RIGHT 65363
# define MLX_KEY_DOWN 65364
# define MLX_KEY_UP 65362
# define MLX_KEY_E 101
# define MLX_KEY_Q 113
# define MLX_KEY_P 112

# define SPEED 0.02f
# define ZOOM_SPEED 0.1f

# define WINDOW_CLOSE 17

typedef enum e_x11mask
{
	Mask_Null,
	Mask_KeyPress = (1L << 0),
	Mask_KeyRelease = (1L << 1)
}	t_e_x11mask;


typedef enum e_fractal
{
	Julia,
	Mandelbrot,
	Mv
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

typedef struct s_img
{
	void	*v;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_env
{
	char		psyche;
	void		*mlx;
	void		*window;
	double		zoom;
	t_vec2i		size;
	t_vec2i		test;
	t_vec2d		offset;
	t_vec2d		kc;
	t_img		image;
	t_e_fractal	fractal_model;
}	t_env;

char	is_valid(char *name, char **params, t_env *env);
int		draw(t_env *env);
int		key_hooks(int keycode, t_env *env);
int		mouse_hook(int x, int y, t_env *env);
void	put_pixel_on_image(t_env *env, int x, int y, int color);
t_vec2i	set_vec2i(int x, int y);
t_vec2d	set_vec2d(double x, double y);

#endif